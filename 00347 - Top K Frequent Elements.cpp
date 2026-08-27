class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int x : nums) {
      mp[x]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto& it : mp) {
      pq.push({it.second, it.first});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<int> answer;
    while (!pq.empty()) {
      answer.push_back(pq.top().second);
      pq.pop();
    }
    return answer;
  }
};
