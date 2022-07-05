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
    bool isValidBST(TreeNode* root) {
        if (not root) return true;
        return validateTree(root, NULL, NULL);
    }
    
    bool validateTree(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (not node) return true;
        if ((low and low -> val >= node -> val) or (high and high -> val <= node -> val)) {
            return false;
        }
        return validateTree(node -> left, low, node) and validateTree(node -> right, node, high);
    }
};