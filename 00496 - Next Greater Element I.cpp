class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;
    for (int i = (int)nums2.size() - 1; i >= 0; i--) {
      while (!st.empty() && st.top() <= nums2[i]) {
        st.pop();
      }
      if (st.empty()) {
        mp[nums2[i]] = -1;
      } else {
        mp[nums2[i]] = st.top();
      }
      st.push(nums2[i]);
    }
    vector<int> answer;
    for (int x : nums1) {
      answer.push_back(mp[x]);
    }
    return answer;
  }
};
