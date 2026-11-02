class Solution {
public:
  int minMoves(vector<int>& nums) {
    int n = (int) nums.size();
    int mn = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      mn = min(mn, nums[i]);
    }
    return sum - n * mn;
  }
};
