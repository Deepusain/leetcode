class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1;
        int k=n;
        while(k>0){
            sum+=(k%10);
            product*=(k%10);
            k/=10;
        }
        if((n%(sum+product))==0) return true;
        return false;
    }
};