class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        long long duplicate = x;
        long long ans = 0;
        while(x != 0) {
            int rem = x % 10;
            ans = ans * 10 + rem;
            x /= 10;
        }
        if(ans == duplicate) {
            return true;
        }
        return false;
    }
};
