#include <stdbool.h>
#include <stdio.h>
#include "util.h"
#include "tree.h"

static struct tree_node *setup_tree(void) {
    struct tree_node *tree = tree_new();
    tree_add(&tree, 6);
    tree_add(&tree, 7);
    tree_add(&tree, 2);
    tree_add(&tree, 11);
    tree_add(&tree, 7);
    return tree;
}

int main(void)
{
    struct tree_node *tree = setup_tree();
    printf("Node count is %d\n", tree_count(tree));
    printf("Tree height is %d\n", tree_height(tree));
    printf("Min value is %d\n", tree_min(tree));
    printf("Max value is %d\n", tree_max(tree));
    tree_free(tree);
}
