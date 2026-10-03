class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        unordered_set<char> seen;
        for (auto& it : password) {
            if (seen.count(it) == 0 && 'a' <= it && it <= 'z') 
                ans += 1;
            else if (seen.count(it) == 0 && 'A' <= it && it <= 'Z') 
                ans += 2;
            else if (seen.count(it) == 0 && '0' <= it && it <= '9') 
                ans += 3;
            else if (seen.count(it) == 0 && (it == '!' || it == '@' || it == '#' || it == '$'))
                ans += 5;
            seen.insert(it);
        }
        return ans;
    }
};
