// Recursion
class Solution {
private:
  bool f(const string& s1, const string& s2) {
    if (s1 == s2) return true;
    if (s1.length() != s2.length()) return false;
    bool res = false;
    int n = s1.length();
    for (int ind = 1; ind < n; ind++) {
      bool swap = f(s1.substr(0, ind), s2.substr(n - ind, ind)) && 
                  f(s1.substr(ind, n - ind), s2.substr(0, n - ind));
      if (swap) {
        res = true;
        break;
      }
      bool not_swap = f(s1.substr(0, ind), s2.substr(0, ind)) && 
                      f(s1.substr(ind, n - ind), s2.substr(ind, n - ind));
      if (not_swap) {
        res = true;
        break;
      }
    }
    return res;
  }
public:
  bool isScramble(string s1, string s2) {
    return f(s1, s2);
  }
};

// Recursion + Memoization
class Solution {
private:
  unordered_map<string, bool> dp;
  bool f(const string& s1, const string& s2) {
    if (s1 == s2) return true;
    if (s1.length() != s2.length()) return false;
    string key = s1 + "_" + s2;
    if (dp.count(key)) return dp[key];
    bool res = false;
    int n = s1.length();
    for (int ind = 1; ind < n; ind++) {
      bool swap = f(s1.substr(0, ind), s2.substr(n - ind, ind)) && 
                  f(s1.substr(ind, n - ind), s2.substr(0, n - ind));
      if (swap) {
        res = true;
        break;
      }
      bool not_swap = f(s1.substr(0, ind), s2.substr(0, ind)) && 
                      f(s1.substr(ind, n - ind), s2.substr(ind, n - ind));
      if (not_swap) {
        res = true;
        break;
      }
    }
    return dp[key] = res;
  }
public:
  bool isScramble(string s1, string s2) {
    dp.clear();
    return f(s1, s2);
  }
};
