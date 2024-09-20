class Solution {
public:
    vector<int> prefix_function(string s) {
    int n = (int) s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
     }
      return pi;
    }

    string shortestPalindrome(string s) {
        string _s = s;
        reverse(_s.begin(), _s.end());
        auto kmp = prefix_function(s + '#' + _s).back();
        string add = s.substr(kmp, s.size() - kmp);
        reverse(add.begin(), add.end());
        return add + s;
    }
};