class Solution {
public:
  int minOperations(vector<int>& nums) {
    int n = (int)nums.size();
    int asc_count = 0;
    int desc_count = 0;
    for (int i = 1; i < n; i++) {
      asc_count += (nums[i] == (nums[i - 1] + 1) % n);
      desc_count += (nums[i - 1] == (nums[i] + 1) % n);
    }
    if (asc_count == n - 1 && nums[0] == 0) {
      return 0;
    }
    if (asc_count == n - 1) {
      int left_rotation = n - nums[0];
      int right_rotation = 3 + nums.back();
      return min(left_rotation, right_rotation);
    }
    if (desc_count == n - 1) {
      int left_rotation = 1 + n - nums.back();
      int right_rotation = 1 + (nums[0] + 1) % n;
      return min(left_rotation, right_rotation);
    }
    return -1;
  }
};
