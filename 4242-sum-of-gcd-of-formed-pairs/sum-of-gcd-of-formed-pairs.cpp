class Solution {
public:
    int GCD (int a,int b){
        if(b%a==0)return a;
        int res =GCD(b%a,a);
        return res;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx=0;
        for(auto& i:nums){
            if(i>mx){
                mx=i;
            }
            int k=GCD(i,mx);
            prefixGcd.push_back(k);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0;
        int j=prefixGcd.size()-1;
        long long res=0;
        while(i<j){
            res+=GCD(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return res;
    }
};