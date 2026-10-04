class Solution {
public:
  void solve(TreeNode* root, int& currentNumber, int& currentFrequency, int& maxFrequency, vector<int>& ans) {
    if (!root) return ;
    solve(root->left, currentNumber, currentFrequency, maxFrequency, ans);
    if (currentNumber == root->val) {
      currentFrequency++;
    } else {
      currentNumber = root->val;
      currentFrequency = 1;
    }
    if (currentFrequency > maxFrequency) {
      ans = {};
      maxFrequency = currentFrequency;
    }
    if (currentFrequency == maxFrequency) {
      ans.push_back(root->val);
    }
    solve(root->right, currentNumber, currentFrequency, maxFrequency, ans);
  }
  vector<int> findMode(TreeNode* root) {
    int currentNumber = 0;
    int currentFrequency = 0;
    int maxFrequency = 0;
    vector<int> ans;
    solve(root, currentNumber, currentFrequency, maxFrequency, ans);
    return ans;
  }
};
