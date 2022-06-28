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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> traversalQueue;
        traversalQueue.push(root);
        vector<int> rightSide;
        while (!traversalQueue.empty()) {
            queue<TreeNode*> children;
            while (!traversalQueue.empty()) {
                TreeNode* current = traversalQueue.front();
                traversalQueue.pop();
                if (traversalQueue.empty()) rightSide.push_back(current -> val);
                if (current -> left) children.push(current -> left);
                if (current -> right) children.push(current -> right);
            }
            
            traversalQueue = children;
        }
        
        return rightSide;
    }
};