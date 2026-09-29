// DFS
class Solution {
private:
  int n, m;
  int dfs(int row, int col, int prev, vector<vector<int>>& matrix) {
    if (row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] <= prev)
      return 0;
    int maxLen = 1;
    maxLen = max(maxLen, 1 + dfs(row - 1, col, matrix[row][col], matrix));
    maxLen = max(maxLen, 1 + dfs(row, col + 1, matrix[row][col], matrix));
    maxLen = max(maxLen, 1 + dfs(row + 1, col, matrix[row][col], matrix));
    maxLen = max(maxLen, 1 + dfs(row, col - 1, matrix[row][col], matrix));
    return maxLen;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        maxLen = max(maxLen, dfs(i, j, -1, matrix));
      }
    }
    return maxLen;
  }
};

// DFS + Memoizattion
class Solution {
private:
  int n, m;
  int dfs(int row, int col, int prev, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] <= prev)
      return 0;
    if (dp[row][col] != -1)
      return dp[row][col];
    int maxLen = 1;
    maxLen = max(maxLen, 1 + dfs(row - 1, col, matrix[row][col], matrix, dp));
    maxLen = max(maxLen, 1 + dfs(row, col + 1, matrix[row][col], matrix, dp));
    maxLen = max(maxLen, 1 + dfs(row + 1, col, matrix[row][col], matrix, dp));
    maxLen = max(maxLen, 1 + dfs(row, col - 1, matrix[row][col], matrix, dp));
    return dp[row][col] = maxLen;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        maxLen = max(maxLen, dfs(i, j, -1, matrix, dp));
      }
    }
    return maxLen;
  }
};

// Using topological sorting
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> indegree(n, vector<int> (m, 0));
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        for (int d = 0; d < 4; d++) {
          int nrow = row + delrow[d];
          int ncol = col + delcol[d];
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[row][col] < matrix[nrow][ncol]) {
            indegree[nrow][ncol]++;
          }
        }
      }
    }
    queue<pair<int, int>> q;
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        if (indegree[row][col] == 0) {
          q.push({row, col});
        }
      }
    }
    int pathLength = 0;
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        auto [row, col] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
          int nrow = row + delrow[d];
          int ncol = col + delcol[d];
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[row][col] < matrix[nrow][ncol]) {
            indegree[nrow][ncol]--;
            if (indegree[nrow][ncol] == 0) {
              q.push({nrow, ncol});
            }
          }
        }
      }
      pathLength++;
    }
    return pathLength;
  }
};
