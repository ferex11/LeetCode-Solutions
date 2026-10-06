class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1 || n < numRows)
            return s;
        string result = "";
        int jumps = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += jumps) {
                result.push_back(s[j]);
                int secondIndex = j + jumps - 2 * i;
                if (i > 0 && i < numRows - 1 && secondIndex  < n) 
                    result.push_back(s[secondIndex]);
            }
        }
        return result;
    }
};
