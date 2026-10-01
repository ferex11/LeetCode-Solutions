// Recursive Traversal

class Solution {
public:
    void inorder(vector<int>& ans, TreeNode* root) {
        if (!root) 
            return;
        inorder(ans, root->left);
        ans.push_back(root->val);
        inorder(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       inorder(ans, root);
       return ans;
    }
};

// Iterative Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (root == NULL) {
            return inorder;
        }
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
