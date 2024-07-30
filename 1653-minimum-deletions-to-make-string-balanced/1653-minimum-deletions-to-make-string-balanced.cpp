class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int minDeletions = 0;
        for (int i =0;i<s.length();i++){
            if (s[i] == 'a'){
                minDeletions = min(minDeletions + 1, bCount);
                }else{
                bCount ++;
                }
        }  
        return minDeletions;
    }
};