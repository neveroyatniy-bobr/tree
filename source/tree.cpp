#include "tree.hpp"

#include <stdio.h>
#include <assert.h>

const char* TreeStrError(TreeError error) {
    switch (error) {
        case TREE_OK:
            return "Выполнено без ошибок";
        default:
            return "Непредвиденная ошибка";
    }
}

void TreePrintError(Tree* tree, const char* file, int line) {
    assert(tree != NULL);

    fprintf(stderr, "Error in %s:%d:\n %s\n", file, line, TreeStrError(tree->last_error));
}

TreeError TreeNodeConstructor(TreeNode* node, tree_elem_t value) {
    assert(node != NULL);

    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    node->value = value;

    return TREE_OK;
}

TreeError TreeNodeDestructor(TreeNode* node) {
    assert(node != NULL);

    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    node->value = 0;

    return TREE_OK;
}

