class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    long long ms = mass;
    sort(asteroids.begin(), asteroids.end());
    for (auto& it : asteroids) {
      if (it > ms) return false;
      ms += it;
    }
    return true;
  }
};
