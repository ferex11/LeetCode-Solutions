// Using DFS
class Solution {
private:
  void dfs(int node, vector<int> adjList[], vector<int>& vis) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
      if (!vis[it]) {
        dfs(it, adjList, vis);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> adjList[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && i != j) {
          adjList[i].push_back(j);
        }
      }
    }
    vector<int> vis(n, 0);
    int provinces = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        provinces++;
        dfs(i, adjList, vis);
      }
    }
    return provinces;
  }
};

// Using DSU
class DisjointSet {
private:
  vector<int> parent;
  vector<int> size;
public:
  DisjointSet(int n) {
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findParent(int node) {
      if (node == parent[node])
          return node;
      return parent[node] = findParent(parent[node]);
  }
  void unionSets(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);
    if (parentU == parentV)
      return;
    if (size[parentU] < size[parentV]) {
      parent[parentU] = parentV;
      size[parentV] += size[parentU];
    } else {
      parent[parentV] = parentU;
      size[parentU] += size[parentV];
    }
  }
};
class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1)
          ds.unionSets(i, j);
      }
    }
    int provinces = 0;
    for (int node = 0; node < n; node++) {
      if (ds.findParent(node) == node)
        provinces++;
    }
    return provinces;
  }
};
