class Solution {
private:
  int n;
  bool check(int mid, long long k, vector<vector<pair<int, long long>>>& adj) {
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
      long long dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      if (dis > k) return false;
      if (node == n - 1) return true;
      if (dis > dist[node]) continue;
      for (auto& it : adj[node]) {
        int adjNode = it.first;
        long long cost = it.second;
        if (cost < mid) continue;
        if (dis + cost < dist[adjNode]) {
          dist[adjNode] = dis + cost;
          pq.push({dist[adjNode], adjNode});
        }
      }
    }
    return false;
  }
public:
  int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    n = (int) online.size();
    vector<vector<pair<int, long long>>> adj(n);
    int low = INT_MAX;
    int high = INT_MIN;
    for (auto& it : edges) {
      int u = it[0];
      int v = it[1];
      long long c = it[2];
      if (!online[u] || !online[v]) continue;
      adj[u].push_back({v, c});
      low = min(low, (int)c);
      high = max(high, (int)c);
    }
    int res = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(mid, k, adj)) {
        res = mid;
        low = mid + 1;
      } else high = mid - 1;
    }
    return res;
  }
};
