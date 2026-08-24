class Solution {
public:
  vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftSum(n, 0);
    for (int i = 1; i < n; i++)
      leftSum[i] = leftSum[i - 1] + nums[i - 1];
    vector<int> rightSum(n, 0);
    for (int i = n - 2; i >= 0; i--)
      rightSum[i] = rightSum[i + 1] + nums[i + 1];
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = abs(leftSum[i] - rightSum[i]);
    return ans;
  }
};


class Solution {
public:
  vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int totalSum = 0;
    for (int x : nums)
      totalSum += x;
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
      int rightSum = totalSum - leftSum - nums[i];
      res[i] = abs(leftSum - rightSum);
      leftSum += nums[i];
    }
    return res;
  }
};
