class Solution {
public:
  bool canFinish(int V, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(V);
    for (auto &it : prerequisites) {
      int u = it[0];
      int v = it[1];
      adj[v].push_back(u);
    }
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
      for (auto &it : adj[i]) {
        indegree[it]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    int count = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      count++;
      for (auto& adjNode : adj[node]) {
        indegree[adjNode]--;
        if (indegree[adjNode] == 0) {
            q.push(adjNode);
        }
      }
    }

    return (count == V);
  }
};
