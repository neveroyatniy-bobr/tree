#ifndef TREE_HPP_
#define TREE_HPP_

#include <stdlib.h>

typedef int tree_elem_t;

struct TreeNode;

struct Tree;

enum TreeError {
    TREE_OK              =  0
};

const char* TreeStrError(TreeError error);

void TreePrintError(Tree* tree, const char* file, int line);

#define TREE_PRINT_ERROR(tree) TreePrintError(tree, __FILE__, __LINE__);

struct TreeNode {
    tree_elem_t value;

    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

struct Tree {
    TreeNode* fictive_elem;

    size_t size;

    TreeError last_error;
};


TreeError TreeNodeConstructor(TreeNode* node, tree_elem_t value);

TreeError TreeNodeDestructor(TreeNode* node);

#endif // TREE_HPP_