class Solution {
public:
    int product_digit(int x){
        int ans=1;
        while(x>0){
            ans*=x%10;
            x/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while((product_digit(n))%t !=0){
            n++;
        }
        return n;
    }
};