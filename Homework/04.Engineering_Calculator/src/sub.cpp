#include "sub.h"
/**
 * Node constructor for Subtraction (-)
 * @param lhs Minuend
 * @param rhs Subtrahend
 */
Sub::Sub(ASTNode* lhs, ASTNode* rhs) : ASTNode("-", lhs, rhs) {}