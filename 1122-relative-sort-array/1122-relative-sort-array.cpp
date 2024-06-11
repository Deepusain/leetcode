class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        map<int,int>mp;
        vector<int>ans;
        int index=0;
        for(int i=0;i<arr1.size();i++)
            mp[arr1[i]]++;
        while(index<arr2.size())
        {
            if(mp[arr2[index]])
            {
                ans.push_back(arr2[index]);
                mp[arr2[index]]--;
            }
            else
                index++;
        }
        for(auto it : mp)
        {   
            int freq=it.second;
            for(int i=0;i<freq;i++)
                ans.push_back(it.first);
        }
        return ans;
    }
};