// Brute Force Approach - DFS/BFS
class Solution {
private:
  bool dfs(int u, int v, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    if (u == v) {
      return true;
    }
    for (int& adjNode : adj[u]) {
      if (!vis[adjNode]) {
        if (dfs(adjNode, v, adj, vis)) {
          return true;
        }
      }
    }
    return false;
  }
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      vector<bool> vis(n + 1, false);
      if (dfs(u, v, adj, vis)) {
        return edge;
      }
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    return {};
  }
};


// Optimal Approach - Using DSU
class DisjointSet {
private:
  vector<int> parent;
  vector<int> size;
public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int node = 1; node <= n; node++) {
      parent[node] = node;
      size[node] = 1;
    }
  }
  int findParent(int node) {
    if (node == parent[node]) {
      return node;
    }
    return parent[node] = findParent(parent[node]);
  }
  void unionSets(int u, int v) {
    int parent_u = findParent(u);
    int parent_v = findParent(v);
    if (parent_u == parent_v) {
      return;
    }
    if (size[parent_u] < size[parent_v]) {
      parent[parent_u] = parent_v;
      size[parent_v] += size[parent_u];
    } else {
      parent[parent_v] = parent_u;
      size[parent_u] += size[parent_v];
    }
  }
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    DisjointSet dsu(n);
    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      if (dsu.findParent(u) == dsu.findParent(v)) {
        return edge;
      }
      dsu.unionSets(u, v);
    }
    return {};
  }
};
