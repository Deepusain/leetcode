class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res="";
        int left = 0;
        int ones =0;
        for(int right =0;right<s.size();right++){
            if(s[right]=='1'){
                ones++;
            }
            while(ones>k){
                if(s[left]=='1'){
                    ones--;
                }
                left++;
            }
            while(ones == k && s[left] == '0') {
                left++;
            }

            if (ones == k){
                int length = right -left +1;
                string substring = s.substr(left, length);

                if (res.empty() || substring.size()<res.size() || (substring.size() == res.size() && substring < res) ){
                   res = substring;
                }
            }
        }
        return res;
    }
};