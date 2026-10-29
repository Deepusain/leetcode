class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a = s.length();
        int b = t.length();

        for(int i=0,j=0;i<s.length()&&j<t.length();j++){
            if(s[i]==t[j]){
                a--;
                i++;
            }
        }
        return a>0? false:true;
    }
};