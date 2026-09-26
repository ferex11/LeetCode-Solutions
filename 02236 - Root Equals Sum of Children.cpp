class Solution {
public:
    bool checkTree(TreeNode* root) {
        int sum = root->left->val + root->right->val;
        return sum == root->val;
    }
};
