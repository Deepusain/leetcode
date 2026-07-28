class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans(n,' ');
        vector<int> freq(26,0);

        for(char c:s){
            freq[c-'a']++;
        }
        int left=0;
        int right = n-1;
        for(int i=0;i<26;i++){
            while(freq[i]>=2){
                ans[left++]= char('a'+i);
                ans[right--]= char('a'+i);
                freq[i] -= 2;
            }
            if(freq[i] == 1){
                ans[n/2] = char('a'+i);
            }
        }
        return ans;
    }
};