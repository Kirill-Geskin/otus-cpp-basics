#include "number.hpp"
/**
 * Node constructor for Number (digits 0-9)
 * @param val
 */
Number::Number(int val) :
    ASTNode(std::to_string(val)),
    val_(val) {}

int Number::value() const {
    return val_;
}