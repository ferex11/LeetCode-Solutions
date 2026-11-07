class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    int m = (int) logs.size();
    int q = (int) queries.size();
    auto lambda = [&](vector<int>& a, vector<int>& b) {
      return a[1] < b[1];
    };
    sort(logs.begin(), logs.end(), lambda);
    vector<int> ans(q);
    vector<pair<int, int>> time_index(q);
    for (int i = 0; i < q; i++) {
      time_index[i] = {queries[i], i};
    }
    sort(time_index.begin(), time_index.end());
    unordered_map<int, int> mp;
    int i = 0;
    int j = 0;
    for (auto [time, ind] : time_index) {
      int start = time - x;
      int end = time;
      while (j < m && logs[j][1] <= end) {
        mp[logs[j][0]]++;
        j++;
      }
      while (i < m && logs[i][1] < start) {
        mp[logs[i][0]]--;
        if (mp[logs[i][0]] == 0) {
          mp.erase(logs[i][0]);
        }
        i++;
      }
      ans[ind] = n - (int)mp.size();
    }
    return ans;
  }
};
