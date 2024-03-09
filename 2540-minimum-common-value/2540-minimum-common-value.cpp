class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int common = INT_MAX;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i] == nums2[j]){
                common = nums1[i];
                break;
            }else if(nums2[j]>nums1[i]){
                i++;
            }else if(nums2[j]<nums1[i]){
                j++;
            }
        }
        if(i == m && j==n && nums1[i] != nums2[j]){
            return -1;
        }
        return common != INT_MAX ? common : -1;
    }
};