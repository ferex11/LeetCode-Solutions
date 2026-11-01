class Solution {
private:
  int n;
  vector<string> ans;
  vector<string> path;
  bool isValid(string s) {
    if ((int) s.size() > 1 && s[0] == '0') {
      return false;
    }
    int num = stoi(s);
    return num <= 255;
  }
  void dfs(int ind, int part, string& s) {
    if (part == 4) {
      if (ind == n) {
        string ip = "";
        for (int i = 0; i < 4; i++) {
          if (i > 0) {
            ip.push_back('.');
          }
          ip += path[i];
        }
        ans.push_back(ip);
      }
      return;
    }
    for (int len = 1; len <= 3; len++) {
      if (ind + len > n) {
        break;
      }
      string cur = s.substr(ind, len);
      if (!isValid(cur)) {
        continue;
      }
      path.push_back(cur);
      dfs(ind + len, part + 1, s);
      path.pop_back();
    }
  }
public:
  vector<string> restoreIpAddresses(string s) {
    n = (int) s.size();
    dfs(0, 0, s);
    return ans;
  }
};
