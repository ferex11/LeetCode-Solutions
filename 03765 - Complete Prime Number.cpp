class Solution {
private:
    bool isPrime(int p) {
        if (p <= 1) return false;
        if (p <= 3) return true;
        if (p % 2 == 0 || p % 3 == 0) return false;
        for (int i = 5; i * i <= p; i += 6) {
            if (p % i == 0 || p % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
public:
    bool completePrime(int num) {
        if (!isPrime(num)) return false;
        int x = num;
        while (x > 0) {
            if (!isPrime(x)) {
                return false;
            }
            x /= 10;
        }
        x = num;
        int digits = log10(num) + 1;
        int base = pow(10, digits - 1);
        while (x > 0) {
            if (!isPrime(x)) {
                return false;
            }
            x %= base;
            base /= 10;
        }
        return true;
    }
};
