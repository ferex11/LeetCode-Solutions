class Solution {
public:
  int minSwaps(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> v = nums;
    auto getDigitSum = [&](int x) -> int {
      int sum = 0;
      while (x > 0) {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    };
    sort(v.begin(), v.end(), [&](int a, int b) {
      int d1 = getDigitSum(a);
      int d2 = getDigitSum(b);
      if (d1 != d2) {
        return d1 < d2;
      }
      return a < b;
    });
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[nums[i]] = i;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      int expected_value = v[i];
      int cur_value = nums[i];
      if (expected_value == cur_value) {
        continue;
      }
      int ind = mp[expected_value];
      nums[i] = expected_value;
      nums[ind] = cur_value;
      mp[expected_value] = i;
      mp[cur_value] = ind;
      count++;
    }
    return count;
  }
};
