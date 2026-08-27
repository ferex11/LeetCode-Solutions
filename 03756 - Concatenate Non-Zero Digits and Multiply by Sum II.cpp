class Solution {
public:
  vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    int n = (int) s.length();
    const int mod = (int) 1e9 + 7;
    vector<int> ans;
    vector<int> nonZeroCnt(n, 0);
    vector<long long> numberUpTo(n, 0);
    vector<long long> digitSumUpTo(n, 0);
    vector<long long> pow10(n + 1, 0);
    pow10[0] = 1;
    nonZeroCnt[0] = (s[0] != '0');
    numberUpTo[0] = (s[0] - '0');
    digitSumUpTo[0] = s[0] - '0';
    for (int i = 1; i <= n; i++) {
      pow10[i] = (pow10[i - 1] * 10) % mod;
      if (i < n) {
        int digit = s[i] - '0';
        nonZeroCnt[i] = nonZeroCnt[i - 1] + (digit != 0 ? 1 : 0);
        if (digit != 0)
          numberUpTo[i] = ((numberUpTo[i - 1] * 10) + digit) % mod;
        else
          numberUpTo[i] = numberUpTo[i - 1];
        digitSumUpTo[i] = digitSumUpTo[i - 1] + digit;
      }
    }
    for (auto& q : queries) {
      int l = q[0];
      int r = q[1];
      long long sum = digitSumUpTo[r] - (l ? digitSumUpTo[l - 1] : 0);
      int k = nonZeroCnt[r] - (l ? nonZeroCnt[l - 1] : 0);
      long long x = numberUpTo[r];
      if (l)
          x = (x - numberUpTo[l - 1] * pow10[k] % mod + mod) % mod;
      ans.push_back(sum % mod * x % mod);
    }
    return ans;
  }
};
