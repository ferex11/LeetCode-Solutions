class Solution {
private:
    vector<string> f(int n) {
        if (n == 1)
            return {"0", "1"};
        vector<string> prev = f(n - 1);
        vector<string> res;
        for (int i = 0; i < (int)prev.size(); i++)
            res.push_back("0" + prev[i]);
        for (int i = 0; i < (int)prev.size(); i++)
            res.push_back("1" + prev[i]);
        return res;
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> s = f(n);
        vector<string> ans;
        for (auto& it : s) {
            int cost = 0;
            for (int i = 0; i < (int)it.length(); i++) {
                if (it[i] == '1')
                    cost += i;
            }
            bool found = false;
            for (int i = 1; i < (int)it.length(); i++) {
                if (it[i - 1] == '1' && it[i] == '1') {
                    found = true;
                    break;
                }
            }
            if (cost <= k && !found)
                ans.push_back(it);
        }
        return ans;
    }
};


class Solution {
private:
    vector<string> ans;
    void f(int ind, int cost, bool prevOne, string& s, int n, int k) {
        if (cost > k)
            return;
        if (ind == n) {
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        f(ind + 1, cost, false, s, n, k);
        s.pop_back();
        if (!prevOne) {
            s.push_back('1');
            f(ind + 1, cost + ind, true, s, n, k);
            s.pop_back();
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        string s = "";
        f(0, 0, false, s, n, k);
        return ans;
    }
};
