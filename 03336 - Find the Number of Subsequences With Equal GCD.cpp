// Recursion
class Solution {
private:
  int n;
  const int mod = 1e9 + 7;
  int f(int ind, int seq1_gcd, int seq2_gcd, vector<int>& nums) {
    if (ind == n) {
      return seq1_gcd != 0 && seq2_gcd != 0 && seq1_gcd == seq2_gcd;
    }
    int not_take = f(ind + 1, seq1_gcd, seq2_gcd, nums) % mod;
    int take_seq1 = f(ind + 1, __gcd(seq1_gcd, nums[ind]), seq2_gcd, nums) % mod;
    int take_seq2 = f(ind + 1, seq1_gcd, __gcd(seq2_gcd, nums[ind]), nums) % mod;
    return (not_take + take_seq1 + take_seq2) % mod;
  }
public:
  int subsequencePairCount(vector<int>& nums) {
    n = (int) nums.size();
    return f(0, 0, 0, nums);
  }
};

// Memoization
class Solution {
private:
  int n;
  const int mod = 1e9 + 7;
  int dp[201][201][201];
  int f(int ind, int seq1_gcd, int seq2_gcd, vector<int>& nums) {
    if (ind == n)
      return seq1_gcd != 0 && seq2_gcd != 0 && seq1_gcd == seq2_gcd;
    if (dp[ind][seq1_gcd][seq2_gcd] != -1)
      return dp[ind][seq1_gcd][seq2_gcd];
    int not_take = f(ind + 1, seq1_gcd, seq2_gcd, nums) % mod;
    int take_seq1 = f(ind + 1, __gcd(seq1_gcd, nums[ind]), seq2_gcd, nums) % mod;
    int take_seq2 = f(ind + 1, seq1_gcd, __gcd(seq2_gcd, nums[ind]), nums) % mod;
    return dp[ind][seq1_gcd][seq2_gcd] = (0LL + not_take + take_seq1 + take_seq2) % mod;
  }
public:
  int subsequencePairCount(vector<int>& nums) {
    n = (int) nums.size();
    memset(dp, -1, sizeof(dp));
    return f(0, 0, 0, nums);
  }
};

// Tabulation
class Solution {
private:
  int n;
  const int mod = 1e9 + 7;
  int dp[201][201][201];
public:
  int subsequencePairCount(vector<int>& nums) {
    n = (int) nums.size();
    memset(dp, 0, sizeof(dp));
    int max_value = *max_element(nums.begin(), nums.end());
    for (int seq1_gcd = 0; seq1_gcd <= max_value; seq1_gcd++) {
      for (int seq2_gcd = 0; seq2_gcd <= max_value; seq2_gcd++) {
        dp[n][seq1_gcd][seq2_gcd] = seq1_gcd != 0 && seq2_gcd != 0 && seq1_gcd == seq2_gcd;
      }
    }
    for (int ind = n - 1; ind >= 0; ind--) {
      for (int seq1_gcd = max_value; seq1_gcd >= 0; seq1_gcd--) {
        for (int seq2_gcd = max_value; seq2_gcd >= 0; seq2_gcd--) {
          int not_take = dp[ind + 1][seq1_gcd][seq2_gcd] % mod;
          int take_seq1 = dp[ind + 1][__gcd(seq1_gcd, nums[ind])][seq2_gcd] % mod;
          int take_seq2 = dp[ind + 1][seq1_gcd][__gcd(seq2_gcd, nums[ind])] % mod;
          dp[ind][seq1_gcd][seq2_gcd] = (0LL + not_take + take_seq1 + take_seq2) % mod;
        }
      }
    }
    return dp[0][0][0];
  }
};

// Space Optimization
class Solution {
public:
  int subsequencePairCount(vector<int>& nums) {
    const int mod = (int) 1e9 + 7;
    int n = (int) nums.size();
    int max_value = *max_element(nums.begin(), nums.end());
    vector<vector<int>> dp(max_value + 1, vector<int> (max_value + 1, 0));
    for (int seq1_gcd = 0; seq1_gcd <= max_value; seq1_gcd++) {
      for (int seq2_gcd = 0; seq2_gcd <= max_value; seq2_gcd++) {
        dp[seq1_gcd][seq2_gcd] = seq1_gcd != 0 && seq2_gcd != 0 && seq1_gcd == seq2_gcd;
      }
    }
    for (int ind = n - 1; ind >= 0; ind--) {
      vector<vector<int>> current_dp(max_value + 1, vector<int> (max_value + 1, 0));
      for (int seq1_gcd = max_value; seq1_gcd >= 0; seq1_gcd--) {
        for (int seq2_gcd = max_value; seq2_gcd >= 0; seq2_gcd--) {
          int not_take = dp[seq1_gcd][seq2_gcd] % mod;
          int take_seq1 = dp[__gcd(seq1_gcd, nums[ind])][seq2_gcd] % mod;
          int take_seq2 = dp[seq1_gcd][__gcd(seq2_gcd, nums[ind])] % mod;
          current_dp[seq1_gcd][seq2_gcd] = (0LL + not_take + take_seq1 + take_seq2) % mod;
        }
      }
      dp = current_dp;
    }
    return dp[0][0];
  }
};
