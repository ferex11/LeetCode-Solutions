class Solution {
public:
    int commonFactors(int a, int b) {
        int comFact = 0;
        for ( int i = 1; i <= max(a, b); i++){
            if(( a % i ) == 0 && ( b % i ) == 0){
                comFact++;
            }
        }
        return comFact ;
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
public:
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int count = 0;
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                count++;
                if (i != g / i) {
                    count++;
                }
            }
        }
        return count;
    }
};
