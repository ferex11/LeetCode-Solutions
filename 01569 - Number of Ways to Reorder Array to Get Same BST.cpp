class Solution {
private:
  const int mod = (int) 1e9 + 7;
  vector<vector<long long>> t;
  int f(vector<int>& nums) {
    int n = (int) nums.size();
    if (n < 3) {
      return 1;
    }
    int root = nums[0];
    vector<int> left, right;
    for (int i = 1; i < n; i++) {
      if (nums[i] < root) {
        left.push_back(nums[i]);
      } else {
        right.push_back(nums[i]);
      }
    }
    long long x = f(left) % mod;
    long long y = f(right) % mod;
    long long z = t[n - 1][(int) left.size()] % mod;
    return ((x * y) % mod * z) % mod;
  }
public:
  int numOfWays(vector<int>& nums) {
    int n = (int) nums.size();
    t.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      t[i] = vector<long long>(i + 1, 1);
      for (int j = 1; j < i; j++) {
        t[i][j] = (t[i - 1][j - 1] + t[i - 1][j]) % mod;
      }
    }
    return (f(nums) - 1) % mod;
  }
};
