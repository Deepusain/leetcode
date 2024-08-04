class Solution {
public:
//     vector subarray(vector<int>& nums, int s,int x){
//         if(x==0){}
//         for(int i = x;i<n && i<s;i++){
            
//         }
//     }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0;i<n;i++){
            int prefsum = 0;
            for(int j=i; j<n;j++){
                prefsum += nums[j];
                v.push_back(prefsum);
            }
        }
        sort(v.begin(),v.end());
        long long sum=0;
        for(int i=left-1;i<=right-1;i++){
            sum+=v[i];
        }
        int mod=1e9+7;
        return sum%mod;
        }
    };