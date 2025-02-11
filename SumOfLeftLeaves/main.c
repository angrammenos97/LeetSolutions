#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    // Check if right leaf
    if (!root)
        return 0;

    // Initialize variables
    int subtree_res = 0;
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    // Add all right subtree
    subtree_res += sumOfLeftLeaves(right);

    // Check left subtree
    if (left) {
        // Left child is leaf
        if (!left->right && !left->left)
            subtree_res += left->val;

        // Add all left subtree
        else
            subtree_res += sumOfLeftLeaves(left);
    }
    
    // printf("%d\n", subtree_res);
    return subtree_res;
}

int main() {
    // Test case 1
    struct TreeNode root;
    struct TreeNode left;
    struct TreeNode right;
    struct TreeNode right_left;
    struct TreeNode right_right;

    root.val = 3;
    root.left = &left;
    root.right = &right;

    left.val = 9;
    left.left = NULL;
    left.right = NULL;

    right.val = 20;
    right.left = &right_left;
    right.right = &right_right;

    right_left.val = 15;
    right_left.left = NULL;
    right_left.right = NULL;

    right_right.val = 7;
    right_right.left = NULL;
    right_right.right = NULL;

    printf("%d\n", sumOfLeftLeaves(&root));

    // Test case 2
    root.val = 1;
    root.left = NULL;
    root.right = NULL;

    printf("%d\n", sumOfLeftLeaves(&root));

    return 0;
}