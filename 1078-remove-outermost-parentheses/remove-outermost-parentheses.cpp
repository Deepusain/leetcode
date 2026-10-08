class Solution {
public:
    string removeOuterParentheses(string s) {
        int check=0;
        string a="";
        string res="";
        for(auto & c: s){
            if(c=='('){
                if(check==0){
                    check++;
                }else{
                    a+=c;
                    check++;
                }
            }else{
                check--;
                if(check>0){
                    a+=c;
                }
            }
        }
        return a;
    }
};