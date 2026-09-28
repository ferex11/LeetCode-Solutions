class Solution {
private:
  int n;
  int findMax(vector<vector<int>>& grid, int x, int y) {
    int mx = 0;
    for (int i = x; i < x + 3; i++) {
      for (int j = y; j < y + 3; j++) {
        mx = max(mx, grid[i][j]);
      }
    }
    return mx;
  }
public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    n = (int) grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int> (n - 2, 0));
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < n - 2; j++) {
        maxLocal[i][j] = findMax(grid, i, j);
      }
    }
    return maxLocal;
  }
};
