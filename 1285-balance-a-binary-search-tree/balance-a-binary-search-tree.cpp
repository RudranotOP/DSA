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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        collectInorderValues(root, sortedValues);

        return buildBalancedFromSorted(sortedValues, 0, (int)sortedValues.size() - 1);
    }
    private:
    void collectInorderValues(TreeNode* currentNode, vector<int>& sortedValues) {
        if (currentNode == nullptr) return;

        collectInorderValues(currentNode->left, sortedValues);
        sortedValues.push_back(currentNode->val);
        collectInorderValues(currentNode->right, sortedValues);
    }

    TreeNode* buildBalancedFromSorted(const vector<int>& sortedValues, int leftIndex, int rightIndex) {
        if (leftIndex > rightIndex) return nullptr;

        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        TreeNode* newRoot = new TreeNode(sortedValues[middleIndex]);
        newRoot->left  = buildBalancedFromSorted(sortedValues, leftIndex, middleIndex - 1);
        newRoot->right = buildBalancedFromSorted(sortedValues, middleIndex + 1, rightIndex);

        return newRoot;
    }
};