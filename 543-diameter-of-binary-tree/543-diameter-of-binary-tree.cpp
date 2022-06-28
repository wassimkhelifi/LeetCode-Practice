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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int diameter = 0;
        height(root, diameter);
        
        return diameter;
    }
    
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int leftSubtreeHeight = height(node -> left, diameter);
        int rightSubtreeHeight = height(node -> right, diameter);
        
        if (leftSubtreeHeight + rightSubtreeHeight > diameter) {
            diameter = leftSubtreeHeight + rightSubtreeHeight;
        }
        
        return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
};