#pragma once

#include <string>

#include "astnode.hpp"

class Add : public ASTNode {
public:
    explicit Add(ASTNode* lhs, ASTNode* rhs);
};