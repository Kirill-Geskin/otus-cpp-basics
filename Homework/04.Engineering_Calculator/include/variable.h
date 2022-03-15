#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
public:
    explicit Variable(std::string val);
    std::string value() const;

private:
    std::string val_;
};