class Solution {
private:
  int cnt = 0;
  bool isSafe(vector<string>& grid, int row, int col, int n) {
      if (grid[row][col] == 'Q') return false;
      int i = row - 1;
      int j = col - 1;
      while (i >= 0 && j >= 0) {
        if (grid[i][j] == 'Q') return false;
        i--;
        j--;
      }
      j = col - 1;
      while (j >= 0) {
        if (grid[row][j] == 'Q') return false;
        j--;
      }
      i = row + 1;
      j = col - 1;
      while (i < n && j >= 0) {
        if (grid[i][j] == 'Q') return false;
        i++;
        j--;
      }
      return true;
  }
  void f(int col, int n, vector<string>& grid) {
    if (col == n) {
      cnt++;
      return;
    }
    for (int row = 0; row < n; row++) {
      if (isSafe(grid, row, col, n)) {
        grid[row][col] = 'Q';
        f(col + 1, n, grid);
        grid[row][col] = '.';
      }
    }
  }
public:
    int totalNQueens(int n) {
      int col = 0;
      vector<string> grid(n, string(n, '.'));
      f(col, n, grid);
      return cnt;
    }
};
