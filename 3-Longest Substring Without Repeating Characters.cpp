// Brute Force Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int hash[256] = {0};
            for (int j = i; j < n; j++) {
                if (hash[s[j]] == 1) break;
                int len = j - i + 1;
                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }
        return maxLen;
    }
};

// Optimal Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> hash(256, -1);
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < n) {
            if (hash[s[right]] != -1) {
                left = max(left, hash[s[right]] + 1);
            }
            int len = right - left + 1;
            res = max(res, len);
            hash[s[right]] = right;
            right++;
        }
        return res;
    }
};
