#include "mul.h"
/**
 * Node constructor for Multiplication (*)
 * @param lhs Multiplier
 * @param rhs Multiplicand
 */
Mul::Mul(ASTNode* lhs, ASTNode* rhs) : ASTNode("*", lhs, rhs) {}