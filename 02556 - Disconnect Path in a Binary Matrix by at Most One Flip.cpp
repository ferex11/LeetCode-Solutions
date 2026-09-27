class Solution {
private:
    int n, m;
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        if (r >= n || c >= m || grid[r][c] == 0) 
            return false;
        if (r == n - 1 && c == m - 1)
            return true;
        grid[r][c] = 0;
        return dfs(r + 1, c, grid) || dfs(r, c + 1, grid);
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n = (int) grid.size();
        m = (int) grid[0].size();
        if (!dfs(0, 0, grid))
            return true;
        grid[0][0] = 1;
        grid[n - 1][m - 1] = 1;
        return !dfs(0, 0, grid);
    }
};
