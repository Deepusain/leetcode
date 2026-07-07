class Solution {
public:
    long long sumAndMultiply(int n) {
        string s= to_string(n);
        string x ="";
        int sum=0;
        for(auto &c : s){
            if(c !='0'){
                x+=c;
                sum += (c - '0');
            }
        }
        if (x.empty()) return 0; 
        return stoll(x) * sum;
    }
};