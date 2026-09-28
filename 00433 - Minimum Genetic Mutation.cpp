class Solution {
public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    set<string> st;
    for (string& s : bank) {
      st.insert(s);
    }
    queue<string> q;
    q.push(startGene);
    st.erase(startGene);
    int level = 0;
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        string current_string = q.front();
        q.pop();
        if (current_string == endGene) {
          return level;
        }
        for (char ch : "ACGT") {
          for (int i = 0; i < (int)current_string.size(); i++) {
            string new_string = current_string;
            new_string[i] = ch;
            if (st.count(new_string)) {
              q.push(new_string);
              st.erase(new_string);
            }
          }
        }
      }
      level++;
    }
    return -1;
  }
};
