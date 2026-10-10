class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for (char ch : s) {
            if (!ans.empty() && ch == '*') {
                ans.pop_back();
            } else if (ch == '#') {
                ans += ans;
            } else if (ch == '%') {
                reverse(ans.begin(), ans.end());
            } else if (isalpha(ch)) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
