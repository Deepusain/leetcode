class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2<101){
            return 0;
        }

        if(num1<101){
            num1=101;
        }

        int ans =0;
        for(int i=num1;i<=num2;i++){
            string s= to_string(i);
            for(int j=1;j<s.size()-1;j++){
                if(s[j]>s[j-1] && s[j]>s[j+1]){
                    ans++;
                }else if(s[j]<s[j-1] && s[j]<s[j+1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};