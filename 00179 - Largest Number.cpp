class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> s;
    for (auto &num : nums)
      s.push_back(to_string(num));
    auto comp = [&](string& a, string& b) {
      return a + b > b + a;
    };
    sort(s.begin(), s.end(), comp);
    string res = "";
    if (s[0] == "0")
      return "0";
    for (auto& it : s)
      res += it;
    return res;
  }
};
