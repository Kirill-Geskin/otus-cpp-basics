#include <cctype>

#include "lexer.hpp"

/**
 * Default constructor
 * @param in Input stream
 */
Lexer::Lexer(std::istream& in) :
    state_{ State::Empty },
    number_{ 0 },
    in_{ in } {
    next_char();
}
/**
 * Get next character from input stream
 */
char Lexer::next_char() {
    in_.get(ch_);
    return ch_;
}
/**
 * Get number parsed from input stream
 */
int Lexer::get_number() const {
    return number_;
}
/**
 * Get operator parsed from input stream
 */
std::string Lexer::get_operator() const {
    return operator_;
}
/**
 * Get Latin character sequence parsed from input stream
 */
std::string Lexer::get_name() const {
    return name_;
}
/**
 * Indicate reaching the end of input stream
 */
bool Lexer::is_end() const {
    return in_.eof() || ch_ == '\n';
}
/**
 * Indicate that character is one of four arithmetic operators
 * @param ch Character read from input stream
 */
bool Lexer::is_operator(char ch) const {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
/**
 * Indicate that character is either left or right parenthesis
 * @param ch Character read from input stream
 */
bool Lexer::is_parenthesis(char ch) const {
    return ch == '(' || ch == ')';
}
/**
 * Parse the next token from input stream and return its type
 */
Lexer::Token Lexer::next_token() {
    for (;;) {
        switch (state_) {
        case State::End:
            return Token::End;
        case State::ReadNumber:
            if (is_end()) {
                state_ = State::End;
                return Token::Number;
            }
            if (std::isdigit(ch_)) {
                // ASCII '0' = 48, this will convert ASCII code of digit character to its integer value
                // If number consists of 2 or more digits (tens, hundreds, ...), each digit to the left
                // has to be multiplied by 10 to represent actual value of number
                number_ = 10 * number_ + (ch_ - '0');
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Number;
        case State::ReadName:
            if (is_end()) {
                state_ = State::End;
                return Token::Name;
            }
            if (std::isalpha(ch_) || std::isdigit(ch_)) {
                name_ += ch_;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Name;
        case State::Empty:
            if (is_end()) {
                state_ = State::End;
                return Token::End;
            }
            if (std::isspace(ch_)) {
                next_char();
                break;
            }
            if (is_operator(ch_)) {
                operator_ = ch_;
                next_char();
                return Token::Operator;
            }
            if (ch_ == '(') {
                next_char();
                return Token::LParenthesis;
            }
            if (ch_ == ')') {
                next_char();
                return Token::RParenthesis;
            }
            if (std::isdigit(ch_)) {
                // ASCII '0' = 48, this will convert ASCII code of digit character to its integer value
                number_ = ch_ - '0';
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_)) {
                name_ = ch_;
                state_ = State::ReadName;
                next_char();
                break;
            }
        }
    }
}