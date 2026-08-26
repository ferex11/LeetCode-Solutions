class Solution {
public:
  int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end());
    int ind = (int) cost.size() - 1;
    int minCost = 0;
    while (ind >= 0) {
      minCost += cost[ind];
      if (ind - 1 >= 0)
        minCost += cost[ind - 1];
      ind -= 3;
    }
    return minCost;
  }
};
