class Solution {
public:
    void generateCombinations(string s, int open, int close, vector<string> &v) {
        if (open == 0 && close == 0) {
            // There's no parenthesis left to add.
            v.push_back(s);
        }
        if (open > 0) {
            s.append("(");
            generateCombinations(s, open - 1, close + 1, v);
            // We need to reset the string before entering the next if statement.
            s = s.substr(0, s.length() - 1);
        }
        if (close > 0) {
            s.append(")");
            generateCombinations(s, open, close - 1, v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        generateCombinations(s, n, 0, v);
        return v;
    }

    bool isWellFormed(string str) {
        stack<char> s;
        for (char c : str) {
            if (c == ')') {
                if (s.empty()) {
                    return false;
                } else if (s.top() == '(') {
                    s.pop();
                } else {
                    // I think this is redundant cause it never goes here
                    return false;
                }
            } else {  // '('
                s.push(c);
            }
        }
        return s.empty();
    }
    void permute(string &str, int begin, vector<string> &v) {
        if (begin == str.length()) {
            v.push_back(str);
        }
        for (int i = begin; i < str.length(); i++ ) {
            swap(str[i], str[begin]);
            permute(str, begin + 1, v);
            swap(str[i], str[begin]);
        }
    }
    vector<string> generateParenthesis_slow(int n) {
        vector<string> v;
        string str = "";
        for (int i = 0; i < n; i++) {
            str.append("()");
        }
        permute(str, 0, v);
        for (auto it = v.begin(); it != v.end(); ++it) {
            if (!isWellFormed(*it)) {
                it = v.erase(it) - 1;
            }
        }
        
        // We need to remove duplicates.
        sort(v.begin(), v.end());
        auto it = unique(v.begin(), v.end());
        v.resize(distance(v.begin(), it));
        
        return v;
    }
};