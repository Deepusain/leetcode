class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSumOfSquares = 0;

        // Har ek starting index 'i' ke liye
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctElements;
            
            // Subarray ko 'i' se lekar 'j' tak extend karte hain
            for (int j = i; j < n; j++) {
                // Element ko set me insert karenge
                // Agar duplicate hoga, toh set ka size change nahi hoga
                distinctElements.insert(nums[j]);
                
                // Distinct elements ke count ka square lekar result me add karenge
                int currentDistinctCount = distinctElements.size();
                totalSumOfSquares += (currentDistinctCount * currentDistinctCount);
            }
        }

        return totalSumOfSquares;
    }
};
