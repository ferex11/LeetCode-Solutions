class Solution {
public:
    bool isAllStars(string &pattern, int i) {
        for (int j = 1; j <= i; j++) {
            if (pattern[j - 1] != '*') {
                return false;
            }
        }
        return true;
    }
    bool isMatch(string text, string pattern) {
        int n = pattern.size();
        int m = text.size();
        vector<bool> previous(m + 1, false);
        vector<bool> current(m + 1, false);
        previous[0] = true;
        for (int i = 1; i <= n; i++) {
            current[0] = isAllStars(pattern, i);
            for (int j = 1; j <= m; j++) {
                if (pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
                    current[j] = previous[j-1];
                } else if (pattern[i-1] == '*') {
                    current[j] = current[j] || current[j-1];
                } else {
                    current[j] = false;
                }
            }
            previous = current;
        }

        return previous[m];
    }
};
