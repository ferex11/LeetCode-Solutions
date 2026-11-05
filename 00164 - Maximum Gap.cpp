class Solution {
public:
  int maximumGap(vector<int>& nums) {
    int n = (int) nums.size();
    if (n < 2) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      ans = max(ans, nums[i + 1] - nums[i]);
    }
    return ans;
  }
};
