#pragma once

#include <string>

#include "astnode.hpp"

class Sub : public ASTNode {
public:
    explicit Sub(ASTNode* lhs, ASTNode* rhs);
};