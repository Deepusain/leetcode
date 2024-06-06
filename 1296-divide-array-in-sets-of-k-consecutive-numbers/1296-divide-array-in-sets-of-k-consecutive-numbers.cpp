class Solution {
public:
     bool isPossibleDivide(vector<int>& nums, int k) {
         map<int,int> map;
         for(int num : nums){
             map[num]++;
         }
         while(map.size()!=0){
             int first = map.begin()->first;
             for(int i=first; i<first+k; i++){
                 if(!map.count(i)){
                     return false;
                 }
                 map[i]--;
                 if(map[i]==0){
                     map.erase(i);
                 }
             }
         }
         return true;
     }
 };