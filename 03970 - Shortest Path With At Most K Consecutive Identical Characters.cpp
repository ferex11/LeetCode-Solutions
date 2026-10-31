class Solution {
private:
  using ll = long long;
  using State = tuple<ll, int, int>;
public:
  int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];
      adj[u].push_back({v, w});
    }
    const ll inf = 4e18;
    vector<vector<ll>> dist (n, vector<ll> (k + 1, inf));
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 1});
    dist[0][1] = 0;
    while (!pq.empty()) {
      auto [d, u, cnt] = pq.top();
      pq.pop();
      if (d != dist[u][cnt]) {
        continue;
      }
      if (u == n - 1) {
        return (int) d;
      }
      for (auto& [v, w] : adj[u]) {
        int new_cnt = 1;
        if (labels[u] == labels[v]) {
          new_cnt = cnt + 1;
        }
        if(new_cnt > k) {
          continue;
        }
        ll new_dist = d + w;
        if (new_dist < dist[v][new_cnt]) {
          dist[v][new_cnt] = new_dist;
          pq.push({new_dist, v, new_cnt});
        }
      }
    }
    return -1;
  }
};
