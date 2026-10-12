class Solution {
public:
  int triangularSum(vector<int>& nums) {
    int n = (int) nums.size();
    while (n != 1) {
      for (int i = 1; i < n; i++) {
        nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
      }
      n--;
    }
    return nums[0];
  }
};
