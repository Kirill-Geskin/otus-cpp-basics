#include "variable.h"
/**
 * Node constructor for Variable (Latin characters)
 * @param val Value
 */
Variable::Variable(std::string val) :
    ASTNode(val),
    val_(val) {}

std::string Variable::value() const {
    return val_;
}