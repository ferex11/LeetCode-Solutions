class Solution {
public:
  bool isValidSerialization(string preorder) {
    vector<string> v;
    stringstream ss(preorder);
    string token;
    while (getline(ss, token, ','))
      v.push_back(token);
    long long vis = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
      if (vis < i) return false;
      if (v[i] == "#") continue;
      vis += 2;
    }
    if (vis != n - 1) return false;
    return true;
  }
};
