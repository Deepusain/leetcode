// class Solution {
// public:
//     int minChanges(int n, int k) {
//         k ^= n;
//         int cnt = __builtin_popcount(k);
//         k &= n;
//         return cnt == __builtin_popcount(k) ? cnt : -1;
//     }
// };
class Solution {
public:
    int minChanges(int n, int k) {
        //It first checks if k is a subset of n using the bitwise AND operator &. If not, it returns -1
        if ((n & k) != k) return -1;
        // count the number of 1st in the XOR result
        int count = 0;
        // XOR of the two number
        int xor_result = n ^ k;
        while (xor_result) {
            // Increment count if the last bit is 1
            count += xor_result & 1;
            //shift bits to the right
            xor_result >>= 1;
        }
        return count;
    }
};