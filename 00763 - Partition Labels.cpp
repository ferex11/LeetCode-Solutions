class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = (int) s.size();
    vector<int> last(26, 0);
    for (int i = 0; i < n; i++) {
      last[s[i] - 'a'] = i;
    }
    int start = 0;
    int end = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      end = max(end, last[s[i] - 'a']);
      if (i == end) {
        ans.push_back(end - start + 1);
        start = i + 1;
      }
    }
    return ans;
  }
};
