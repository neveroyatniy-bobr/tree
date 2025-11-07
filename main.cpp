#include "tree.hpp"

#include <stdio.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL));

    Tree tree;
    TreeInit(&tree);
    
    const size_t nodes_count = 10;
    TreeNode nodes[nodes_count] = {};
    for (size_t i = 0; i < nodes_count; i++) {
        TreeNodeInit(&nodes[i], rand()%100);
        TreeAdd(&tree, &nodes[i]);
    }
    
    TREE_DUMP(&tree);

    TreeDestroy(&tree);

    return 0;
}