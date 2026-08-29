class Solution {
private:
  bool checkRow(int row, char val, vector<vector<char>>& board) {
    int cnt = 0;
    for (int j = 0; j < 9; j++) {
      if (board[row][j] == val) cnt++;
    }
    return cnt == 1;
  }
  bool checkCol(int col, char val, vector<vector<char>>& board) {
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
      if (board[i][col] == val) cnt++;
    }
    return cnt == 1;
  }
  bool check3by3(int row, int col, char val, vector<vector<char>>& board) {
    int cnt = 0;
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[rowStart + i][colStart + j] == val) cnt++;
      }
    }
    return cnt == 1;
  }
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        if (!checkRow(i, board[i][j], board)) return false;
        if (!checkCol(j, board[i][j], board)) return false;
        if (!check3by3(i, j, board[i][j], board)) return false;
      }
    }
    return true;
  }
};
