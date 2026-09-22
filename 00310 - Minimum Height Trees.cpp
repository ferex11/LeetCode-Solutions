class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> res;
    if (n == 0) {
      return res;
    }   
    if (n == 1) {
      res.push_back(0);
      return res;
    }
    vector<int> degree(n, 0);
    vector<vector<int>> adj(n);
    for (auto& it : edges) {
      int u = it[0];
      int v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      degree[u]++;
      degree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1)
        q.push(i);
    }
    int remainingNodes = n;
    while (remainingNodes > 2) {
      int sz = q.size();
      remainingNodes -= sz;
      for (int i = 0; i < sz; i++) {
        int node = q.front();
        q.pop();
        for (auto& adjNode : adj[node]) {
          degree[adjNode]--;
          if (degree[adjNode] == 1)
            q.push(adjNode);
        }
      }
    }
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }
    return res;
  }
};
