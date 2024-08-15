class Solution {
public:
    bool isPalindrome(string s){
        for (int i=0,j=s.length()-1;j>i;j--,i++){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int i=0 , j=s.length()-1;i<j;i++,j--){
            if(s[i] !=s[j]){
                if(isPalindrome(s.substr(i, j-i))){
                    return true;
                }else if(isPalindrome(s.substr(i+1, j-i))){
                    return true;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};