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
public:
struct SubtreeInfo {
        int depth;
        TreeNode* node;
    };
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        SubtreeInfo result = findDeepestSubtree(root);
        return result.node;
    }

private:
    SubtreeInfo findDeepestSubtree(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return {0, nullptr};
        }

        SubtreeInfo leftInfo = findDeepestSubtree(currentNode->left);
        SubtreeInfo rightInfo = findDeepestSubtree(currentNode->right);

        if (leftInfo.depth == rightInfo.depth) {
            return {leftInfo.depth + 1, currentNode};
        }

        if (leftInfo.depth > rightInfo.depth) {
            return {leftInfo.depth + 1, leftInfo.node};
        }

        return {rightInfo.depth + 1, rightInfo.node};
    }
};