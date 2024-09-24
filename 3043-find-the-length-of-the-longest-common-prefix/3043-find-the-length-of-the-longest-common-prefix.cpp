class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>set;
        for(auto& i : arr1){
            while(set.find(i)==set.end() && i>0){
                set.insert(i);
                i/=10;
            }
        }
        int ans=0;
         for(auto& i:arr2){
             while(set.find(i)==set.end() && i>0){
                 i/=10;
             }
             if(i>0){
                 ans = max(ans,(int)log10(i)+1);
             }
            
         }
         return ans;
    }
};