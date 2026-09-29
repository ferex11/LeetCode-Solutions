class Solution {
public:
    int smallestEvenMultiple(int n) {
        for(int i = 1; i <= n; i++){
            int ans = i * n;
            if((ans % 2 == 0) && (ans % n == 0)){
                return ans ;
            }
        }
        return 2;
    }
};


class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
public:
    int smallestEvenMultiple(int n) {
        return lcm(2, n);
    }
};
