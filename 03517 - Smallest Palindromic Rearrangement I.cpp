class Solution {
public:
  string smallestPalindrome(string s) {
    int n = (int)s.size();
    if (n == 1) {
      return s;
    }
    vector<int> count(26, 0);
    for (char ch : s) {
      count[ch - 'a']++;
    }
    string ans = "";
    int ind = -1;
    for (int i = 0; i < 26; i++) {
      if (count[i] > 0) {
        ans += string(count[i] / 2, i + 'a');
      }
      if (count[i] % 2 == 1) {
        ind = i;
      }
    }
    string temp = ans;
    reverse(temp.begin(), temp.end());
    if (ind == -1) {
      ans += temp;
      return ans;
    }
    ans.push_back(ind + 'a');
    ans += temp;
    return ans;
  }
};
