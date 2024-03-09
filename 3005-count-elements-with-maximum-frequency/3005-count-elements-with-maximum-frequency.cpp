class Solution {

public:

    int maxFrequencyElements(vector<int>& nums) {

        map<int, int> mp;

        // count frequency

        for(int n : nums) {

            mp[n]++;

        }

        // iterate map, get largest frequency

        int maxfreq = -1;

        for(auto it : mp) {

            maxfreq = max(maxfreq, it.second);

        }

        // add all nums with largest frequency

        int ans = 0;

        for(auto it : mp) {

            if(it.second == maxfreq) ans+= it.second;

        }

        return ans;

    }

}; 