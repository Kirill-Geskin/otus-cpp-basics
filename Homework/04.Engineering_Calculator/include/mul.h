#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
public:
    explicit Mul(ASTNode* lhs, ASTNode* rhs);
};