class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if (n == 0)
            return 0;
        int ind = 0;
        while (ind < n && s[ind] == ' ')
            ind++;
        if (ind == n)
            return 0;
        int sign = 1;
        if (s[ind] == '+') {
            ind++;
        } else if (s[ind] == '-') {
            sign = -1;
            ind++;
        }
        long long res = 0;
        while (ind < n && isdigit(s[ind])) {
            int digit = s[ind] - '0';
            res = (res * 10) + digit;
            if (res * sign >= INT_MAX)
                return INT_MAX;
            else if (res * sign <= INT_MIN)
                return INT_MIN;
            ind++;
        }
        return (int) res * sign;
    }
};
