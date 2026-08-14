class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0,right=0,max_len=0;
        int n =s.length();
        unordered_map <char,int>mp;
        while(right<n){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                mp[s[left]]--;
                left++;
            }
            max_len=max(max_len,(right-left+1));
            right++;
        }
        return max_len;
    }
};