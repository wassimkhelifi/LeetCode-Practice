/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string serialized = "";
        generateString(root, serialized);
        return serialized;
    }
    
    void generateString(TreeNode* node, string& serialized) {
        if (!node) {
            serialized += "N,";
            return;
        }
        
        serialized += to_string(node -> val) + ",";
        
        generateString(node -> left, serialized);
        generateString(node -> right, serialized);
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        vector<string> preorder;
        string current = "";
        for (auto& element : data) {
            if (element == ',') {
                preorder.push_back(current);
                current = "";
            } else {
                current += element;
            }
        }
        
        int preorderIndex = 0;
        return generateTree(preorder, preorderIndex);
    }
    
    TreeNode* generateTree(vector<string>& preorder, int& preorderIndex) {
        string value = preorder[preorderIndex++];
        if (value == "N") return NULL;
        
        TreeNode* root = new TreeNode(stoi(value));
        root -> left = generateTree(preorder, preorderIndex);
        root -> right = generateTree(preorder, preorderIndex);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));