class Solution {
public:
  vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    int n = (int) nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> ans;
    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
      p[i + 1] = p[i] + nums[i];
    }
    for (int& x : queries) {
      int ind = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
      long long left = 1LL * x * ind - p[ind];
      long long right = (p[n] - p[ind]) - (1LL * x * (n - ind));
      ans.push_back(left + right);
    }
    return ans;
  }
};
