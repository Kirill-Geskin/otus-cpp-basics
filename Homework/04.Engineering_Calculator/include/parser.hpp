#pragma once

#include <istream>

#include "astnode.hpp"
#include "lexer.hpp"

class Parser {
public:
    explicit Parser(Lexer& lexer);                      // Initialize object of type Parser explicitly
    Parser(const Parser& other) = delete;               // Prevent initialization with other object of type Parser
    Parser& operator=(const Parser& other) = delete;    // Prevent '=' operator usage
    ~Parser();

    ASTNode* parse();

private:
    Lexer& lexer_;
    Lexer::Token tok_;

    void next_token();

    ASTNode* expr();
    ASTNode* term();
    ASTNode* prim();
};