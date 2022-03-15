#include "astnode.hpp"
/**
 * Leaf constructor (node without child nodes)
 * @param repr String representation of created node
 */
ASTNode::ASTNode(const std::string& repr) :
    repr_(repr),
    lhs_{ nullptr },
    rhs_{ nullptr } {}
/**
 * Node constructor (node with one or two child nodes)
 * @param repr String representation of created node
 * @param lhs Left hand side node
 * @param rhs Right hand side node
 */
ASTNode::ASTNode(const std::string& repr, ASTNode* lhs, ASTNode* rhs) :
    repr_(repr),
    lhs_{ lhs },
    rhs_{ rhs } {}
/**
 * Destructor
 */
ASTNode::~ASTNode() {
    delete lhs_;
    delete rhs_;
}
/**
 * Return node name as string
 * @return
 */
std::string ASTNode::repr() const {
    return repr_;
}
/**
 * Print Abstract Syntax Tree to output stream
 * @param out Output stream
 */
void ASTNode::print(std::ostream& out) const {
    inner_print(out, 0);
}
/**
 * Private implementation of ASTNode::print
 * @param out Output stream
 * @param indent Indentation size (times 4 spaces)
 */
void ASTNode::inner_print(std::ostream& out, size_t indent) const {
    if (lhs_) {
        lhs_->inner_print(out, indent + 1);
    }
    for (size_t i = 0; i < indent; ++i) {
        out << "    ";
    }
    out << repr_ << '\n';
    if (rhs_) {
        rhs_->inner_print(out, indent + 1);
    }
}