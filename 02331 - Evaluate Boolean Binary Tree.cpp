class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) 
            return root->val;
        bool leftRes = evaluateTree(root->left);
        bool rightRes = evaluateTree(root->right);
        if (root->val == 2)
            return leftRes || rightRes;
        return leftRes && rightRes;
    }
};
