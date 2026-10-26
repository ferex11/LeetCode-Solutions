class Solution {
public:
  bool isValid(int adjrow, int adjcol, int n, int m) {
    return adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol < m;
  }
  long long dfs(int row, int col, long long& count, vector<vector<int>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    count += grid[row][col];
    for (int i = 0; i < 4; i++) {
      int adjrow = row + delrow[i];
      int adjcol = col + delcol[i];
      if (isValid(adjrow, adjcol, n, m) && !vis[adjrow][adjcol] && grid[adjrow][adjcol] != 0) {
        dfs(adjrow, adjcol, count, grid, vis, delrow, delcol);
      }
    }
    return count;
  }
  int countIslands(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis (n, vector<int> (m, 0));
    int islands = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && grid[i][j] != 0) {
          long long count = 0;
          long long countIslands = dfs(i, j, count, grid, vis, delrow, delcol);
          if (countIslands % k == 0) {
            islands++;
          }
        }
      }
    }
    return islands;
  }
};
