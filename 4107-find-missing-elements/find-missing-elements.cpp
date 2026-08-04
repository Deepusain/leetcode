class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int a=nums[0];
        for(int i=0;i<nums.size();i++){
            while(a<nums[i]){
                res.push_back(a);
                a++;
            }
            a++;
        }
        return res;
    }
};