#include "tree.hpp"

#include <stdio.h>

int main() {
    TreeNode root;
    TreeNodeConstructor(&root, ROOT_VALUE);

    const size_t nodes_count = 10;

    TreeNode nodes[nodes_count];
    for (size_t node_i = 0; node_i < nodes_count; node_i++) {
        TreeNodeConstructor(&nodes[node_i], (int)node_i);
    }

    TreeNodeSetLeft(&root, &nodes[1]);

    TreeNodeSetLeft(&nodes[1], &nodes[2]);
    TreeNodeSetRight(&nodes[1], &nodes[3]);
    TreeNodeSetLeft(&nodes[2], &nodes[5]);
    TreeNodeSetRight(&nodes[2], &nodes[6]);
    TreeNodeSetLeft(&nodes[3], &nodes[4]);
    TreeNodeSetLeft(&nodes[5], &nodes[7]);
    TreeNodeSetRight(&nodes[6], &nodes[8]);
    TreeNodeSetLeft(&nodes[8], &nodes[9]);
    TreeNodeSetRight(&nodes[9], &nodes[0]);

    Tree tree;
    tree.root = &root;
    tree.size = nodes_count;
    tree.last_error = TREE_OK;

    
    TREE_DUMP(&tree);

    return 0;
}