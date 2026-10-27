class Solution {
private:
  vector<bool> vis;
  void dfs(int u, vector<vector<int>>& rooms) {
    vis[u] = true;
    for (int v : rooms[u]) {
      if (!vis[v]) {
        dfs(v, rooms);
      }
    }
  }
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = (int) rooms.size();
    vis.assign(n, false);
    dfs(0, rooms);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        return false;
      }
    }
    return true;
  }
};
