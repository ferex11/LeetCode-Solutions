class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> less;
    vector<int> equal;
    vector<int> greater;
    for (auto it : nums) {
      if (it < pivot) less.push_back(it);
      else if (it == pivot) equal.push_back(it);
      else greater.push_back(it);
    }
    int index = 0;
    for (auto it : less) {
      nums[index] = it;
      index++;
    }
    for (auto it : equal) {
      nums[index] = it;
      index++;
    }
    for (auto it : greater) {
      nums[index] = it;
      index++;
    }
    return nums;
  }
};

class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ans;
    for (int x : nums) {
      if (x < pivot)
        ans.push_back(x);
    }
    for (int x : nums) {
      if (x == pivot)
        ans.push_back(x);
    }
    for (int x : nums) {
      if (x > pivot)
        ans.push_back(x);
    }
    return ans;
  }
};
