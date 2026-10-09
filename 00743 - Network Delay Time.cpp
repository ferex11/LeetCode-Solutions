class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    const long long INF = 1e9;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : times) {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      adj[u].push_back({v, w});
    }
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    dist[k] = 0;
    while (!pq.empty()) {
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      for (auto it : adj[node]) {
        int adjNode = it.first;
        int wt = it.second;
        if (wt + dis < dist[adjNode]) {
          dist[adjNode] = wt + dis;
          pq.push({dist[adjNode], adjNode});
        }
      }
    }
    int minTime = INT_MIN;
    for (int i = 1; i <= n; i++) {
      if (dist[i] == INF)
        return -1;
      minTime = max(minTime, dist[i]);
    }
    return minTime;
  }
};
