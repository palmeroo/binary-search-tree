#include <stdbool.h>
#include <stdio.h>
#include "util.h"
#include "tree.h"

#define ASSERT(test) \
    { \
        int result = (int)(test); \
        char display = result ? '.' : 'F'; \
        printf("%c", display); \
    }

static struct tree_node *setup_tree(void) {
    struct tree_node *tree = tree_new();
    tree_add(&tree, 6);
    tree_add(&tree, 7);
    tree_add(&tree, 2);
    tree_add(&tree, 11);
    tree_add(&tree, 7);
    return tree;
}

static void test_tree_count(void) {
    struct tree_node *tree = setup_tree();
    int expected = 4;
    int actual = tree_count(tree);
    ASSERT(expected == actual);
    tree_free(tree);
}

static void test_tree_height(void) {
    struct tree_node *tree = setup_tree();
    int expected = 3;
    int actual = tree_height(tree);
    ASSERT(expected == actual);
    tree_free(tree);
}

static void run_tests() {
    test_tree_count();
    test_tree_height();
    printf("\n");
}

int main(void)
{
    run_tests();
    struct tree_node *tree = setup_tree();
    printf("Min value is %d\n", tree_min(tree));
    printf("Max value is %d\n", tree_max(tree));
    tree_free(tree);
}
