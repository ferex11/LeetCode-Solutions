class Solution {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    int n = (int) nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) {
        nums[i] *= -1;
      }
    }
    sort(nums.rbegin(), nums.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (i * 2 < n) {
        ans += nums[i] * nums[i];
      } else {
        ans -= nums[i] * nums[i];
      }
    }
    return ans;
  }
};
