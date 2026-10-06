class Solution {
private:
    int n;
    int m;
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    bool dfs(int r, int c, int ind, vector<vector<bool>>& vis, vector<vector<char>>& board, string& word) {
        vis[r][c] = true;
        if (ind == (int) word.length()) {
            return true;
        }
        auto isValid = [&](int nr, int nc) -> bool {
            return nr >= 0 && nr < n && nc >= 0 && nc < m;
        };
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (isValid(nr, nc) && !vis[nr][nc] && board[nr][nc] == word[ind]) {
                if (dfs(nr, nc, ind + 1, vis, board, word)) {
                    return true;
                }
            }
        }
        vis[r][c] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 1, vis, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
