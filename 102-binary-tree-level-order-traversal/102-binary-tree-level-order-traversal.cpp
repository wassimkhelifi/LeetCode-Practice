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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> traversalQueue;
        traversalQueue.push(root);
        vector<vector<int>> levels;
        
        while (!traversalQueue.empty()) {
            queue<TreeNode*> children;
            vector<int> level;
            while (!traversalQueue.empty()) {
                TreeNode* current = traversalQueue.front();
                traversalQueue.pop();
                level.push_back(current -> val);
                if (current -> left) children.push(current -> left);
                if (current -> right) children.push(current -> right);
            }
            
            levels.push_back(level);
            traversalQueue = children;
        }
        
        return levels;
    }
};