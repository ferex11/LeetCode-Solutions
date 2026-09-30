class Solution {
public:
  long long gcdSum(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> v(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
      mx = max(mx, nums[i]);
      v[i] = __gcd(mx, nums[i]);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    int low = 0;
    int high = n - 1;
    while (low < high) {
      ans += __gcd(v[low], v[high]);
      low++;
      high--;
    }
    return ans;
  }
};
