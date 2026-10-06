class Solution {
private:
    unordered_map<int, int> mpp;
    int maxFreq = 0;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        int sum = root->val + leftSum + rightSum;
        mpp[sum]++;
        maxFreq = max(maxFreq, mpp[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mpp.clear();
        dfs(root);
        vector<int> res;
        for (auto it : mpp) {
            if (it.second == maxFreq)
                res.push_back(it.first);
        }
        return res;
    }
};
// Time Complexity: O(n)
// Space Compexity: (n)
