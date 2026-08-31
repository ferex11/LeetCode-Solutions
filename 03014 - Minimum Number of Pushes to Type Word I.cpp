class Solution {
public:
  int minimumPushes(string word) {
    int ans = 0;
    int n = (int)word.size();
    int x = 1;
    while (n >= 0) {
      if (n >= 8) {
        ans += 8 * x;
        n -= 8;
        x++;
      } else {
        ans += n * x;
        break;
      }
    }
    return ans;
  }
};
