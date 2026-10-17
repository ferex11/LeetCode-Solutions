class Solution {
private:
  const int mod = 1e9 + 7;
  struct Node {
    long long sum = 0;
    long long sq = 0;
    long long lazy = 0;
  };
  vector<Node> tree;
  int n;
  void apply(int node, int l, int r, long long val) {
    long long len = r - l + 1;
    long long old_sum = tree[node].sum;
    tree[node].sq = (tree[node].sq + 2LL * val % mod * old_sum % mod + len % mod * val % mod * val % mod) % mod;
    tree[node].sum = (old_sum + len % mod * val % mod) % mod;
    tree[node].lazy = (tree[node].lazy + val) % mod;
  }
  void push(int node, int l, int r) {
    if (tree[node].lazy == 0 || l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    long long val = tree[node].lazy;
    apply(2 * node, l, mid, val);
    apply(2 * node + 1, mid + 1, r, val);
    tree[node].lazy = 0;
  }
  void update(int node, int l, int r, int ql, int qr, long long val) {
    if (ql > r || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      apply(node, l, r, val);
      return;
    }
    push(node, l, r);
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, ql, qr, val);
    update(2 * node + 1, mid + 1, r, ql, qr, val);
    tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % mod;
    tree[node].sq = (tree[2 * node].sq + tree[2 * node + 1].sq) % mod;
  }
public:
  int sumCounts(vector<int>& nums) {
    n = (int) nums.size();
    tree.assign(4 * n, Node());
    vector<int> last(100001, -1);
    long long ans = 0;
    for (int r = 0; r < n; r++) {
      int p = last[nums[r]];
      update(1, 0, n - 1, p + 1, r, 1);
      last[nums[r]] = r;
      ans = (ans + tree[1].sq) % mod;
    }
    return (int) ans;
  }
};
