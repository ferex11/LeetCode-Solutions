class Solution {
private:
  void computeLPS(vector<int>& pattern, vector<int>& lps) {
    int n = (int) pattern.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n) {
      if (pattern[i] == pattern[len]) {
        len++;
        lps[i] = len;
        i++;
      } else {
        if (len != 0) {
          len = lps[len - 1];
        } else {
          lps[i] = 0;
          i++;
        }
      }
    }
  }
  bool KMP(vector<int>& pattern, vector<int>& text) {
    int n = (int) text.size();
    int m = (int) pattern.size();
    vector<int> lps(m, 0);
    computeLPS(pattern, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
      if (pattern[j] == text[i]) {
        i++;
        j++;
      }
      if (j == m) {
        return true;
      } else if (i < n && pattern[j] != text[i]) {
        if (j != 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
    }
    return false;
  }
public:
  int sortableIntegers(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    int result = 0;
    auto check = [&](vector<int>& v1, vector<int>& v2) -> bool {
      vector<int> v = v2;
      v.insert(v.end(), v2.begin(), v2.end());
      return KMP(v1, v);
    };
    for (int k = 1; k <= n; k++) {
      if (n % k != 0) {
        continue;
      }
      bool is_valid = true;
      for (int start = 0; start < n; start += k) {
        vector<int> v1(nums.begin() + start, nums.begin() + start + k);
        vector<int> v2(sorted.begin() + start, sorted.begin() + start + k);
        if (!check(v1, v2)) {
          is_valid = false;
          break;
        }
      }
      if (is_valid) {
        result += k;
      }
    }
    return result;
  }
};
