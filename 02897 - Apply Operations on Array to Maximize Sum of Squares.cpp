class Solution {
public:
  int maxSum(vector<int>& nums, int k) {
    const int mod = 1e9 + 7;
    vector<int> count(32, 0);
    for (int &num : nums) {
      for (int b = 0; b < 32; b++) {
        if (num & (1 << b)) {
          count[b]++;
        }
      }
    }
    int ans = 0;
    while (k--) {
      long long cur = 0;
      for (int b = 0; b < 32; b++) {
        if (count[b]) {
          count[b]--;
          cur |= (1 << b);
        }
      }
      ans = (ans + (cur * cur)) % mod;
    }
    return ans;
  }
};
