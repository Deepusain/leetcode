class Solution {
public:
    vector<string> check(int open, int close) {
        if (open == 0) {
            return { string(close, ')') };
        }
        
        if (open == close) {
            vector<string> sub_res = check(open - 1, close);
            for (string& s : sub_res) {
                s = "(" + s;
            }
            return sub_res;
        }
        
        vector<string> res;
        
        vector<string> left_choice = check(open - 1, close);
        for (string s : left_choice) {
            res.push_back("(" + s);
        }
        
        vector<string> right_choice = check(open, close - 1);
        for (string s : right_choice) {
            res.push_back(")" + s);
        }
        
        return res;
    }

    vector<string> generateParenthesis(int n) {
        return check(n, n);
    }
};
