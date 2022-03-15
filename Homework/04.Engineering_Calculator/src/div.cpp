#include "div.h"
/**
 * Node constructor for Division (/)
 * @param lhs Dividend
 * @param rhs Divisor
 */
Div::Div(ASTNode* lhs, ASTNode* rhs) : ASTNode("/", lhs, rhs) {}