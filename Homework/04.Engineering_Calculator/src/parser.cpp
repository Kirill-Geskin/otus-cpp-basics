#include "parser.hpp"
#include "number.hpp"
#include "variable.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

using Token = Lexer::Token;
/**
 * Default constructor
 * @param lexer Lexer object
 */
Parser::Parser(Lexer& lexer) : lexer_(lexer) {}
/**
 * Trivial destructor
 */
Parser::~Parser() = default;
/**
 * Parse Abstract Syntax Tree node object from expression
 */
ASTNode* Parser::parse() {
    return expr();
}
/**
 * Get next token from lexer
 */
void Parser::next_token() {
    tok_ = lexer_.next_token();
}
/**
 * Parse addition and subtraction
 */
ASTNode* Parser::expr() {
    ASTNode* root = term();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                root = new Add(root, term());
                break;
            case '-':
                root = new Sub(root, term());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}
/**
 * Parse multiplication and division
 */
ASTNode* Parser::term() {
    ASTNode* root = prim();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '*':
                root = new Mul(root, prim());
                break;
            case '/':
                root = new Div(root, prim());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}
/**
 * Parse base element (number or variable name)
 */
ASTNode* Parser::prim() {
    ASTNode* node = nullptr;
    next_token();
    switch (tok_) {
    case Token::Number:
        node = new Number(lexer_.get_number());
        break;
    case Token::Name:
        node = new Variable(lexer_.get_name());
        break;
    default:
        break;
    }
    next_token();
    return node;
}