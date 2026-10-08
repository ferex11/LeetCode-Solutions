class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> f(26, 0);
        vector<int> F(26, 0);
        for (int i = 0; i < n; i++) {
            if ('a' <= word[i] && word[i] <= 'z') f[word[i] - 'a']++;
            else F[word[i] - 'A']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (f[i] > 0 && F[i] > 0) cnt++;
        }
        return cnt;
    }
};
