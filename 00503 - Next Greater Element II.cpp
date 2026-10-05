class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> answer(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--) {
      int ind = i % n;
      while (!st.empty() && st.top() <= nums[ind]) {
        st.pop();
      }
      if (ind < n && !st.empty()) {
        answer[ind] = st.top();
      }
      st.push(nums[ind]);
    }
    return answer;
  }
};
