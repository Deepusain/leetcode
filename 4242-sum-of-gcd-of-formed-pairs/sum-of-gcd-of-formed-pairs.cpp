class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx=0;
        for(auto& i:nums){
            if(i>mx){
                mx=i;
            }
            int k=gcd(i,mx);
            prefixGcd.push_back(k);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0;
        int j=prefixGcd.size()-1;
        long long res=0;
        while(i<j){
            res+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return res;
    }
};