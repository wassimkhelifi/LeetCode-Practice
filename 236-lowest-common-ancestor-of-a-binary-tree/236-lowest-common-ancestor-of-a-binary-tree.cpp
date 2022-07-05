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
        if (not root) return NULL;
        
        bool subtreeContainsNode = false;
        bool leftSubtreeContainsNode = false;
        bool rightSubtreeContainsNode = false;
        
        if (root == p) {
            traverseOne(root, p, subtreeContainsNode);
        } else if (root == q) {
            traverseOne(root, q, subtreeContainsNode);
        }
        if (subtreeContainsNode) {
            return root;
        }
        
        traverseTwo(root -> left, p, q, leftSubtreeContainsNode);
        traverseTwo(root -> right, p, q, rightSubtreeContainsNode);
        
        if (leftSubtreeContainsNode and not rightSubtreeContainsNode) {
            return lowestCommonAncestor(root -> left, p, q);
        } else if (not leftSubtreeContainsNode and rightSubtreeContainsNode) {
            return lowestCommonAncestor(root -> right, p, q);
        } else {
            return root;
        }
    }
    
    void traverseOne(TreeNode* node, TreeNode* target, bool& exists) {
        if (not node) return;
        
        if (node == target) {
            exists = true;
        }
        
        traverseOne(node -> left, target, exists);
        traverseOne(node -> right, target, exists);
    }
    
    void traverseTwo(TreeNode* node, TreeNode* targetOne, TreeNode* targetTwo, bool& exists) {
        if (not node) return;
        
        if (node == targetOne or node == targetTwo) {
            exists = true;
        }
        
        traverseTwo(node -> left, targetOne, targetTwo, exists);
        traverseTwo(node -> right, targetOne, targetTwo, exists);
    }
};