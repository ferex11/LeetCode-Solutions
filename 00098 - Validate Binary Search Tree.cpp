class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long minValue, long long maxValue) {
        if (!root)
            return true;
        if (root->val >= maxValue || root->val <= minValue)
            return false;
        return isValidBST(root->left, minValue, root->val) && isValidBST(root->right, root->val, maxValue);
    }
};
