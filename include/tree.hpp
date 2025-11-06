#ifndef TREE_HPP_
#define TREE_HPP_

#include <stdlib.h>

typedef int tree_elem_t;

struct TreeNode;

struct Tree;

enum TreeError {
    TREE_OK              =  0
};

static const tree_elem_t ROOT_VALUE = 1234113251;

static const char DUMP_FILE_NAME[] = "dump_file.html";
static const char BUILD_DUMP_FILE_NAME[] = "build_dump_file.dot";
static const size_t BUILD_DUMP_COMMAND_SIZE = 128;
static const unsigned int DUMP_FONT_SIZE = 36;

const char* TreeStrError(TreeError error);

void TreePrintError(Tree* tree, const char* file, int line);

#define TREE_PRINT_ERROR(tree) TreePrintError(tree, __FILE__, __LINE__)

struct TreeNode {
    tree_elem_t value;

    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

struct Tree {
    TreeNode* root;

    size_t size;

    TreeError last_error;
};


TreeError TreeNodeConstructor(TreeNode* node, tree_elem_t value);

TreeError TreeNodeDestructor(TreeNode* node);

TreeNode* TreeNodeGetParent(TreeNode* node);

TreeNode* TreeNodeGetLeft(TreeNode* node);

TreeError TreeNodeSetLeft(TreeNode* node, TreeNode* new_left);

TreeNode* TreeNodeGetRight(TreeNode* node);

TreeError TreeNodeSetRight(TreeNode* node, TreeNode* new_right);

tree_elem_t TreeNodeGetValue(TreeNode* node);

TreeError TreeNodeSetValue(TreeNode* node, tree_elem_t new_value);

void TreeDump(Tree* tree, const char* file, int line);

#define TREE_DUMP(tree) TreeDump(tree, __FILE__, __LINE__)

#endif // TREE_HPP_