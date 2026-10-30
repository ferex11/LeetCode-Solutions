class Solution {
private:
  int n;
  int time;
  int cols;
  vector<vector<int>> adj;
  vector<int> tin, tout, euler_tour;
  vector<int> tree;
  vector<vector<int>> up;
  vector<int> depth;
  void dfs(int u, int p, int d, string& s) {
    depth[u] = d;
    up[u][0] = p;
    tin[u] = time;
    euler_tour[time] = 1 << (s[u] - 'a');
    time++;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      dfs(v, u, d + 1, s);
    }
    tout[u] = time;
    euler_tour[time] = 1 << (s[u] - 'a');
    time++;
  }
  void build(int node, int low, int high, vector<int>& a) {
    if (low == high) {
      tree[node] = a[low];
      return;
    }
    int mid = low + (high - low) / 2;
    build(2 * node + 1, low, mid, a);
    build(2 * node + 2, mid + 1, high, a);
    tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
  }
  void update(int node, int low, int high, int pos, int val) {
    if (low == high) {
      tree[node] = val;
      return;
    }
    int mid = low + (high - low) / 2;
    if (pos <= mid) {
      update(2 * node + 1, low, mid, pos, val);
    } else {
      update(2 * node + 2, mid + 1, high, pos, val);
    }
    tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
  }
  int query(int node, int low, int high, int ql, int qr) {
    if (low > qr || high < ql) {
      return 0;
    }
    if (ql <= low && high <= qr) {
      return tree[node];
    }
    int mid = low + (high - low) / 2;
    int left_res = query(2 * node + 1, low, mid, ql, qr);
    int right_res = query(2 * node + 2, mid + 1, high, ql, qr);
    return left_res ^ right_res;
  }
  void buildAncestorTable() {
    for (int j = 1; j < cols; j++) {
      for (int node = 0; node < n; node++) {
        if (up[node][j - 1] != -1) {
          up[node][j] = up[up[node][j - 1]][j - 1];
        }
      }
    }
  }
  int lca(int u, int v) {
    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int j = cols - 1; j >= 0; j--) {
      if (diff & (1 << j)) {
        u = up[u][j];
      }
    }
    if (u == v) {
      return u;
    }
    for (int j = cols - 1; j >= 0; j--) {
      if (up[u][j] != up[v][j]) {
        u = up[u][j];
        v = up[v][j];
      }
    }
    return up[u][0];
  }
public:
  vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
    this->n = n;
    adj.assign(n, {});
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cols = 1;
    while ((1LL << cols) <= n) {
      cols++;
    }
    tin.assign(n, 0);
    tout.assign(n, 0);
    depth.assign(n, 0);
    euler_tour.assign(2 * n, 0);
    up.assign(n, vector<int> (cols, -1));
    time = 0;
    dfs(0, -1, 0, s);
    tree.resize(8 * n);
    build(0, 0, 2 * n - 1, euler_tour);
    buildAncestorTable();
    vector<bool> ans;
    for (auto& q : queries) {
      stringstream ss(q);
      string type;
      ss >> type;
      if (type == "update") {
        int u;
        char c;
        ss >> u >> c;
        int char_value = 1 << (c - 'a');
        s[u] = c;
        update(0, 0, 2 * n - 1, tin[u], char_value);
        update(0, 0, 2 * n - 1, tout[u], char_value);
      } else {
        int u, v;
        ss >> u >> v;
        int lca_node = lca(u, v);
        char c = s[lca_node];
        int char_value = 1 << (c - 'a');
        int mask = query(0, 0, 2 * n - 1, 0, tin[u]) ^ query(0, 0, 2 * n - 1, 0, tin[v]) ^ char_value;
        ans.push_back((mask & (mask - 1)) == 0);
      }
    }
    return ans;
  }
};
