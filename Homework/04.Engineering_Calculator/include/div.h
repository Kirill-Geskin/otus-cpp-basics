#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
public:
    explicit Div(ASTNode* lhs, ASTNode* rhs);
};