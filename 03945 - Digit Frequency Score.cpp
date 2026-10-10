class Solution {
public:
  int digitFrequencyScore(int n) {
    vector<int> freq(10, 0);
    while (n > 0) {
      int rem = n % 10;
      freq[rem]++;
      n /= 10;
    }
    int sum = 0;
    for (int i = 1; i < 10; i++) {
      sum += i * freq[i];
    }
    return sum;
  }
};
