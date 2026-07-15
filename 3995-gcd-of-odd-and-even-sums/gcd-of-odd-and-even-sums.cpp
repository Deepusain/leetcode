class Solution {
public:
    int gcdOfOddEvenSums(int n) 
    {
        int so=0,se=0;
        for(int i=1;i<=n*2;i++)
        {
            if(i%2==0) se+=i;
            else so+=i;
        }
        int y=0;
        for(int i=1;i<=n*2;i++)
        {
            if(so%i==0 && se%i==0) y=max(y,i);
        }
        return y;
    }
};


// class Solution {
// public:
//     int gcdOfOddEvenSums(int n) {
//         return n;
//     }
// };