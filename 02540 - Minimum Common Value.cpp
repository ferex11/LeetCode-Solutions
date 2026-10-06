// Brute Force Approach

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j])
                    return nums1[i];
            }
        }
        return -1;
    }
};

// Optimal Approach : Two Pointer

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = 0;
        int right  = 0;
        while (left < n && right < m) {
            if (nums1[left] == nums2[right])
                return nums1[left];
            else if (nums1[left] < nums2[right])
                left++;
            else
                right++;
        }
        return -1;
    }
};
