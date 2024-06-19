class Solution {
public:

    bool helper(long long int &mid,vector<int>& bloomDay, int &m, int &k){
        int n = bloomDay.size();
        int bouq = 0;
        int total=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= mid){ //mid is the particular time, if values below the time are less then mid then it means that the flower has bloomed because it is less than mid
            total++;
            }
            else{
                if(total >= k){ //if values in total are greater it means we can forma bouquet
                    bouq++;
                }
                total = 0; //we reset to form a new streak
            }
            if(total>=k) //if at any point this condn satisfy
            {
                bouq++;
                total = 0;
            }
        }
        if(total >=k) bouq++;
        return (bouq >=m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1; //garden has flowers less than required
        long long int left = 1;
        long long int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left<right){
            long long int mid = (left+right)/2;
            if(helper(mid,bloomDay,m,k)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};