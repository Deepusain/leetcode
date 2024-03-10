class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count =0;
        sort(nums.begin() , nums.end());
        int i=0, j=nums.size()-1;
        while(i < j){
          if(nums[i] + nums[j] == k){     // found elements just increase counter
            count++; i++; j--;
          } 
		  else if(nums[i] + nums[j] > k) j--;  // sum is large so decrease the bigger element, i.e. jth element
          else i++;    // sum is small so increase the smaller element, i.e. ith element
        }
        return count;
    }
};