class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while (num){
            sum += (num % 10);
            num /= 10;
        }
        if (sum < 10)
            return sum ;        
        else
            return addDigits(sum);
    }
    
};


class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num > 9) {
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
            sum = 0;
        }
        return num;
    }
};


class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        else if (num % 9 == 0) return 9;
        return num % 9;
    }
};
