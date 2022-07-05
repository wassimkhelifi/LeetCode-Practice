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

/**
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) inorderIndex[inorder[i]] = i;
        
        int preorderIndex = 0;
        
        return generateTree(preorder, 0, inorder.size() - 1, preorderIndex, inorderIndex);
    }
    
    TreeNode* generateTree(vector<int>& preorder, int left, int right, int& preorderIndex, map<int, int>& inorderIndex) {
        if (left > right) return NULL;
        
        int value = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(value);
        root -> left = generateTree(preorder, left, inorderIndex[value] - 1, preorderIndex, inorderIndex);
        root -> right = generateTree(preorder, inorderIndex[value] + 1, right, preorderIndex, inorderIndex);
        return root;
    }
};
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderToIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderToIndex[inorder[i]] = i;
        }
        
        int preorderIndex = 0;
        return generateTree(preorder, 0, inorder.size() - 1, preorderIndex, inorderToIndex);
    }
    
    TreeNode* generateTree(vector<int>& preorder, int left, int right, int& preorderIndex, map<int, int>& inorderToIndex) {
        if (left > right) {
            return NULL;
        }
        
        int value = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(value);
        root -> left = generateTree(preorder, left, inorderToIndex[value] - 1, preorderIndex, inorderToIndex);
        root -> right = generateTree(preorder, inorderToIndex[value] + 1, right, preorderIndex, inorderToIndex);
        return root;
    }
};