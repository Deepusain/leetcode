class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos,
             int tight,
             int started,
             int prev1,
             int prev2) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][started][prev1][prev2])
            return dp[pos][tight][started][prev1][prev2];

        vis[pos][tight][started][prev1][prev2] = true;

        Node ans = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt = dfs(
                    pos + 1,
                    ntight,
                    0,
                    10,
                    10
                );

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            }
            else {

                if (!started) {

                    Node nxt = dfs(
                        pos + 1,
                        ntight,
                        1,
                        d,
                        10
                    );

                    ans.cnt += nxt.cnt;
                    ans.wav += nxt.wav;
                }
                else {

                    long long add = 0;

                    if (prev2 != 10) {

                        if (prev1 > prev2 && prev1 > d)
                            add++;

                        if (prev1 < prev2 && prev1 < d)
                            add++;
                    }

                    Node nxt = dfs(
                        pos + 1,
                        ntight,
                        1,
                        d,
                        prev1
                    );

                    ans.cnt += nxt.cnt;

                    ans.wav += nxt.wav
                               + add * nxt.cnt;
                }
            }
        }

        return dp[pos][tight][started][prev1][prev2] = ans;
    }

    long long solve(long long x) {

        if (x < 0)
            return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1,
                            long long num2) {

        return solve(num2)
             - solve(num1 - 1);
    }
};


// class Solution {
// public:
//     long long totalWaviness(long long num1, long long num2) {
//         if(num2<101) return 0;
//         if(num1<=100){
//             num1=101;
//         }
//         long long ans=0;
//         for(long long num = num1 ;num<=num2;num++){
//             string s = to_string(num);
//             for(long long i=1;i<s.size()-1;i++){
//                 if(s[i]>s[i+1] && s[i]>s[i-1]){
//                     ans++;
//                 }else if(s[i]<s[i+1] && s[i]<s[i-1]){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };