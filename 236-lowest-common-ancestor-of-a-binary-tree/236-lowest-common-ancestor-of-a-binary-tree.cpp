/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        bool existsInSubtree = false;
        bool existsInLeftSubtree = false;
        bool existsInRightSubtree = false;
        
        if (root == p) traverseOne(root, q, existsInSubtree);
        else if (root == q) traverseOne(root, p, existsInSubtree);
        if (existsInSubtree) return root;
        
        traverseTwo(root -> left, p, q, existsInLeftSubtree);
        traverseTwo(root -> right, p, q, existsInRightSubtree);
        
        if (existsInLeftSubtree && !existsInRightSubtree) return lowestCommonAncestor(root -> left, p, q);
        else if (!existsInLeftSubtree && existsInRightSubtree) return lowestCommonAncestor(root -> right, p, q);
        else return root;
    }
    
    void traverseOne(TreeNode* node, TreeNode* target, bool& exists) {
        if (!node) return;
        if (node == target) exists = true;
        traverseOne(node -> left, target, exists);
        traverseOne(node -> right, target, exists);
    }
    
    void traverseTwo(TreeNode* node, TreeNode* targetOne, TreeNode* targetTwo, bool& exists) {
        if (!node) return;
        if (node == targetOne || node == targetTwo) exists = true;
        traverseTwo(node -> left, targetOne, targetTwo, exists);
        traverseTwo(node -> right, targetOne, targetTwo, exists);
    }
};