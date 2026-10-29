class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    int n = (int) grid.size();
    int m = (int) grid[0].size();
    vector<vector<bitset<1024>>> dp(n, vector<bitset<1024>> (m));
    dp[0][0][grid[0][0]] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        bitset<1024> up;
        bitset<1024> left;
        if (i > 0) {
          up = dp[i - 1][j];
        }
        if (j > 0) {
          left = dp[i][j - 1];
        }
        bitset<1024> combined = up | left;
        for (int x = 0; x < 1024; x++) {
          if (combined[x]) {
            int res = x ^ grid[i][j];
            dp[i][j][res] = 1;
          }
        }
      }
    }
    for (int x = 0; x < 1024; x++) {
      if (dp[n - 1][m - 1][x]) {
        return x;
      }
    }
    return 0;
  }
};
