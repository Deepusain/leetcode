class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0;
        int curr_Altitude=0;
        for(int i:gain){
            curr_Altitude +=i;
            if(curr_Altitude>res) res=curr_Altitude;
        }
        return res;
    }
};