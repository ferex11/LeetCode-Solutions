class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& word : words) {
            int weight = 0;
            for (int i = 0; i < (int)word.length(); i++) {
                weight += weights[word[i] - 'a'];
            }
            char ch = 'z' - (weight % 26);
            ans.push_back(ch);
        }
        return ans;
    }
};
