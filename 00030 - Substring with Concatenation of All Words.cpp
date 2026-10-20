class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (s.empty() || words.empty()) {
      return ans;
    }
    int n = (int) s.size();
    int k = (int) words[0].size();
    int m = (int) words.size();
    if (n < m * k) {
      return ans;
    }
    unordered_map<string, int> mp;
    for (string &x : words) {
      mp[x]++;
    }
    for (int i = 0; i < k; i++) {
      unordered_map<string, int> seen;
      int l = i;
      int count = 0;
      for (int r = i; r + k <= n; r += k) {
        string word = s.substr(r, k);
        if (!mp[word]) {
          seen.clear();
          count = 0;
          l = k + r;
          continue;
        }
        count++;
        seen[word]++;
        while (seen[word] > mp[word]) {
          string left_word = s.substr(l, k);
          seen[left_word]--;
          count--;
          l += k;
        }
        if (count == m) {
          ans.push_back(l);
          string left_word = s.substr(l, k);
          seen[left_word]--;
          count--;
          l += k;
        }
      }
    }
    return ans;
  }
};
