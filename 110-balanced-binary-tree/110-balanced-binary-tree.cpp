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
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;
//         bool balanced = true;
//         height(root, balanced);
//         return balanced;
//     }
    
//     bool height(TreeNode* node, bool& balanced) {
//         if (!node) return 0;
//         int leftSubtreeHeight = height(node -> left, balanced);
//         int rightSubtreeHeight = height(node -> right, balanced);
//         if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) balanced = false;
//         return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
//     }
// };


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
    
    int height(TreeNode* root, bool& balanced) {
        if (!root) return 0;
        int leftHeight = height(root -> left, balanced);
        int rightHeight = height(root -> right, balanced);
        if (abs(leftHeight - rightHeight) > 1) balanced = false;
        return max(leftHeight, rightHeight) + 1;
    }
};
