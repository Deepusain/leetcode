class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        unordered_set<int> set(nums.begin(), nums.end());
        while(set.find(ans)!= set.end()){
            ans+=k;
        }
        return ans;
    }
};