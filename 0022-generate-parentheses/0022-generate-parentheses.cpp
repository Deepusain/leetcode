class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string g = "";
        vector<string> res;
        function<void(string, int,int)> df = [&](string gg, int ind, int indd){
            if(indd==0 and ind==0) {
                res.push_back(gg);
                return;
            }
            if(ind>0){
            df(gg+'(', ind-1, indd+1);
            }
            if(indd>0){
            df(gg+')',ind, indd-1);
            }
            return;
        };
        df(g, n,0);
        return res;
    }
};