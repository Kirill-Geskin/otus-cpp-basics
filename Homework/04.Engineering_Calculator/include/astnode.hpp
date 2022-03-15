// OTUS C++ basic course homework.
// ASTNode

#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ASTNode {
public:
    explicit ASTNode(const std::string& repr);          // Initialize object of type ASTNode explicitly
    ASTNode(const std::string& repr, ASTNode* lhs, ASTNode* rhs);
    ASTNode(const ASTNode& other) = delete;             // Prevent initialization with other object of type ASTNode
    ASTNode& operator=(const ASTNode& other) = delete;  // Prevent '=' operator usage
    ~ASTNode();

    std::string repr() const;
    void print(std::ostream& out) const;

private:
    std::string repr_;
    ASTNode* lhs_;
    ASTNode* rhs_;

    void inner_print(std::ostream& out, size_t indent) const;
};