class Solution {
public:
  int longestSubsequence(vector<int>& nums) {
    int n = nums.size();
    int xr = 0;
    int zeros = 0;
    for (int num : nums) {
      xr ^= num;
      if (!num) {
        zeros++;
      }
    }
    if (xr != 0) {
      return n;
    }
    if (zeros == n) {
      return 0;
    }
    return n - 1;
  }
};
