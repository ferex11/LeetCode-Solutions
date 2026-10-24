class Solution {
public:
  int maxCoins(vector<int>& piles) {
    int n = (int) piles.size();
    int ans = 0;
    sort(piles.begin(), piles.end());
    int i = n - 2;
    int j = 0;
    while (j < i) {
      ans += piles[i];
      i -= 2;
      j++;
    }
    return ans;
  }
};
