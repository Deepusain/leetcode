// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//         string s= to_string(n);
//         string x ="";
//         long long sum=0;
//         for(auto &c : s){
//             if(c !='0'){
//                 x+=c;
//                 sum += (c - '0');
//             }
//         }
//         if (x.empty()) return 0; 
//         return stoll(x) * sum;
//     }
// };


class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1;
        
        while (n > 0) {
            int digit = n % 10;
            
            if (digit != 0) {
                x += digit * multiplier;
                sum += digit;
                multiplier *= 10;
            }
            
            n /= 10;
        }
        
        return x * sum;
    }
};