#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/////////////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int distributeCoins(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    int moves = 0;
    // Handle left subtree
    moves += distributeCoins(root->left);
    if (root->left && root->left->val != 1) {
        int diff = root->left->val - 1;
        root->val += diff;
        root->left->val -= diff;
        moves += diff > 0 ? diff : -diff;
    }
    // Handle right subtree
    moves += distributeCoins(root->right);
    if (root->right && root->right->val != 1) {
        int diff = root->right->val - 1;
        root->val += diff;
        root->right->val -= diff;
        moves += diff > 0 ? diff : -diff;
    }

    return moves;
}

////////////////////////////////////////////
typedef struct TreeNode TreeNode;

TreeNode* createTreeNode(int val) {
    if (val == -1) {
        return NULL;
    }
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* arrayToBinaryTree(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    TreeNode* root = createTreeNode(nums[start]);

    if (root) {
        root->left = arrayToBinaryTree(nums,  2 * start + 1, end);
        root->right = arrayToBinaryTree(nums, 2 * start + 2, end);
    }

    return root;
}

void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    // Testcase 1
    // int tree[] = {3, 0, 0};
    // TreeNode* root = arrayToBinaryTree(tree, 0, 2);

    // Testcase 2
    int tree[] = {0, 3, 0};
    TreeNode* root = arrayToBinaryTree(tree, 0, 2);

    // Testcase 3
    // int tree[] = {1, 0, 0, -1, 3};
    // TreeNode* root = arrayToBinaryTree(tree, 0, 4);


    printTree(root);
    printf("\n");

    printf("Total moves = %d\n", distributeCoins(root));
    return 0;
}