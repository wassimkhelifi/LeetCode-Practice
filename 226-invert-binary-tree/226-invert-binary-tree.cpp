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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        
        queue<TreeNode*> traversalQueue;
        traversalQueue.push(root);
        while (!traversalQueue.empty()) {
            TreeNode* current = traversalQueue.front();
            traversalQueue.pop();
            if (current -> left) {
                traversalQueue.push(current -> left);
            }
            if (current -> right) {
                traversalQueue.push(current -> right);
            }
            
            TreeNode* temp = current -> left;
            current -> left = current -> right;
            current -> right = temp;
        }
        
        return root;
    }
};