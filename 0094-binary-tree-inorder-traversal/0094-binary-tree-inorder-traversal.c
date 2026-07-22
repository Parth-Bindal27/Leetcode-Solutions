/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void helper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL)
        return;

    helper(root->left, arr, index);

    arr[(*index)++] = root->val;

    helper(root->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int *)malloc(100 * sizeof(int));
    int index = 0;

    helper(root, arr, &index);

    *returnSize = index;

    return arr;
}