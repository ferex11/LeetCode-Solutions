class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        auto valid = [&](int nr, int nc) -> bool {
            return nr >= 0 && nr < n && nc >= 0 && nc < m;
        };
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            int r = cell.first;
            int c = cell.second;
            pq.pop();
            if (d > dist[r][c]) continue;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (valid(nr, nc)) {
                    int edge_weight = (grid[r][c] == d + 1) ? 0 : 1;
                    if (edge_weight + dist[r][c] < dist[nr][nc]) {
                        dist[nr][nc] = edge_weight + dist[r][c];
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
