#pragma once
#include <istream>
#include <string>

/**
 *  Lexer interface
 */
class Lexer {
public:
    enum class Token {
        Number,         // Integer numbers
        Operator,       // Arithmetic operators: +-*/
        End,            // End Of File or newline, i.e. no more data in input stream
        LParenthesis,   // '(' character
        RParenthesis,   // ')' character
        Name,           // Latin alphabet characters
    };

    explicit Lexer(std::istream& in);               // Initialize object of type Lexer explicitly
    Lexer(const Lexer& other) = delete;             // Prevent initialization with other object of type Lexer
    Lexer& operator=(const Lexer& other) = delete;  // Prevent '=' operator usage

    Token next_token();

    int get_number() const;
    std::string get_operator() const;
    std::string get_name() const;

protected:
    bool is_parenthesis(char ch) const;
    bool is_operator(char ch) const;

private:
    /**
     * Inner state of lexer
     */
    enum class State {
        Empty,          // Start reading symbols
        ReadNumber,     // Read numbers from stdin
        ReadName,       // Read characters from stdin
        End,            // Stop reading symbols
    };

    State state_;
    std::string name_;
    int number_;
    std::string operator_;
    char ch_;
    std::istream& in_;

    char next_char();
    bool is_end() const;
};