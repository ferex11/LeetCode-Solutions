class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    if (sum > 9 * num) {
      return "";
    }
    int r = sum % 9;
    string res(sum / 9, '9');
    if (r > 0) {
      res.push_back('0' + r);
    }
    res.append(num - (int) res.size(), '0');
    return res;
  }
};
