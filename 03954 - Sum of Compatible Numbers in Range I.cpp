class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for (int num = 1; num <= n + k; num++) {
            if (abs(n - num) <= k && (n & num) == 0)
                ans += num;
        }
        return ans;
    }
};
