class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = s.size();
        int ans = 0;
        int i = k - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }
        
        return ans;
    }
};
