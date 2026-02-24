/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int addRootToLeafNumbers(TreeNode* node, int currentNumber) {
        if (!node) return 0;

        int updatedNumber = currentNumber * 2 + node->val;

        if (!node->left && !node->right) {
            return updatedNumber;
        }

        int leftSum = addRootToLeafNumbers(node->left, updatedNumber);
        int rightSum = addRootToLeafNumbers(node->right, updatedNumber);

        return leftSum + rightSum;
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        return addRootToLeafNumbers(root, 0);
    }
};