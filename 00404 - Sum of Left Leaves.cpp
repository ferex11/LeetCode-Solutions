class Solution {
private:   
    int dfs(TreeNode* root, bool isLeft) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            if (isLeft)
                return root->val;
            else
                return 0;
        }
        int leftSubtree = dfs(root->left, true);
        int rightSubtree = dfs(root->right, false);
        return leftSubtree + rightSubtree;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};
// Time Comlexity: (n)
// Space Complexity: O(h)
