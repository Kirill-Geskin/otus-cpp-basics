#include "add.h"
/**
 * Node constructor for Addition (+)
 * @param lhs Addend
 * @param rhs Addend
 */
Add::Add(ASTNode* lhs, ASTNode* rhs) : ASTNode("+", lhs, rhs) {}