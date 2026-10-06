class Solution {
public:
    vector<int> grayCode(int n) {
        n = 1 << n;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};
