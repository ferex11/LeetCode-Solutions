class Solution {
public:
    char processStr(string s, long long k) {
        int64_t len = 0;
        for (char c : s) {
            if (c == '*') {
                if (len > 0) {
                    len--;
                }
            } else if (c == '#') {
                len *= 2;
            } else if (c == '%') {
                continue;
            } else {
                len++;
            }
        }
        if (k >= len) {
            return '.';
        }
        for (int i = (int) s.length() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '%') {
                k = len - k - 1;
            } else if (s[i] == '#') {
                len /= 2;
                k = (k >= len) ? k - len : k;
            } else {
                len--;
            }
            if (k == len) {
                return s[i];
            }
        }
        return '.';
    }
};
