class Solution {
public:
    string Replaces(string s, int k) {
        string ans="";
        for (int i = 0; i < s.length(); i += k) {
            int sum = 0;
            for (int j = i; j < i + k && j < s.length(); j++) {
                sum += (s[j] - '0');
            }
            ans += to_string(sum);
        }
        return ans;
    }
    string digitSum(string s, int k) {
        while(s.length()>k) s=Replaces(s,k);
        return s;
    }
};