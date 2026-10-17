class Solution {
public:
    int GetDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>aftersorted(nums);

        auto lambda =[&](int num1,int num2){
            int num1DigitSum = GetDigitSum(num1); //TL log10(num)
            int num2DigitSum = GetDigitSum(num2);
            if(num1DigitSum != num2DigitSum){
                return num1DigitSum < num2DigitSum;
            }
            return num1<num2;
        };

        sort(begin(aftersorted),end(aftersorted),lambda); //TL nlogn * log10(max_num)

        unordered_map<int,int>ValToIdx;
        for(int i=0;i<n;i++){
            ValToIdx[nums[i]]=i;
        }
        int SwapCount=0;
        for(int i=0;i<n;i++){
            int ExpectedVal = aftersorted[i];
            int CurrVal = nums[i];
            if(ExpectedVal == CurrVal ) continue;

            int ExpectedValIdx = ValToIdx[ExpectedVal];
            nums[i]=ExpectedVal;
            nums[ExpectedValIdx]=CurrVal;
            ValToIdx[ExpectedVal]=i;
            ValToIdx[CurrVal] = ExpectedValIdx;
            SwapCount++;
        }
        return SwapCount;
    }
};

// #include <vector>
// #include <numeric>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();
        
//         // 1. Ek vector banayein jo {digit_sum, original_value, original_index} store karega
//         // Hum pair<pair<int, int>, int> use kar sakte hain
//         vector<pair<pair<int, int>, int>> tracking_arr(n);
        
//         for (int i = 0; i < n; i++) {
//             int temp = nums[i];
//             int digit_sum = 0;
//             while (temp > 0) {
//                 digit_sum += temp % 10;
//                 temp /= 10;
//             }
//             // {{digit_sum, original_value}, original_index}
//             tracking_arr[i] = {{digit_sum, nums[i]}, i};
//         }
        
//         // 2. Custom sorting: pairs by default pehle first element (digit_sum) 
//         // ko compare karte hain, fir second element (original_value) ko.
//         sort(tracking_arr.begin(), tracking_arr.end());
        
//         // 3. Minimum Swaps count karne ke liye cycle finding logic
//         vector<bool> visited(n, false);
//         int total_swaps = 0;
        
//         for (int i = 0; i < n; i++) {
//             // Agar element pehle se sahi jagah par hai ya visit ho chuka hai, toh skip karein
//             if (visited[i] || tracking_arr[i].second == i) {
//                 continue;
//             }
            
//             // Cycle ka size find karna
//             int cycle_size = 0;
//             int current_idx = i;
            
//             while (!visited[current_idx]) {
//                 visited[current_idx] = true;
//                 // Agla index woh hoga jahan is element ko originally hona chahiye tha
//                 current_idx = tracking_arr[current_idx].second;
//                 cycle_size++;
//             }
            
//             // Agar cycle ka size > 0 hai, toh swaps = cycle_size - 1
//             if (cycle_size > 0) {
//                 total_swaps += (cycle_size - 1);
//             }
//         }
        
//         return total_swaps;
//     }
// };
