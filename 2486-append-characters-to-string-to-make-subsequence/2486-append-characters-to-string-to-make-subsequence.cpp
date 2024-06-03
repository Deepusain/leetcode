class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i=0 , j=0;
        while(i<m && j<n){
            if(s[i]==t[j]){
                j++;
            }
            i++;
            // if(j ==0){
            //     if(s[i] == t[j]){
            //         j++;
            //     }
            //     i++;
            // }else {
            //     if(s[i] == t[j]){
            //         j++;
            //         i++;
            //     }else{
            //         break;
            //     }
            // }
        }
        return n-j;

    }
};