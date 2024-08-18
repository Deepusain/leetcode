class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-Heap to store the ugly numbers
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        unordered_set<long long> seen;
    
        // Start with the first ugly number
        minHeap.push(1);
        seen.insert(1);
    
        long long currentUglyNumber = 1;
    
        for (int i = 0; i < n; ++i) {
            // Extract the smallest number
            currentUglyNumber = minHeap.top();
            minHeap.pop();
        
            // Generate new ugly numbers
            if (seen.find(currentUglyNumber * 2) == seen.end()) {
                minHeap.push(currentUglyNumber * 2);
                seen.insert(currentUglyNumber * 2);
            }
            if (seen.find(currentUglyNumber * 3) == seen.end()) {
                minHeap.push(currentUglyNumber * 3);
                seen.insert(currentUglyNumber * 3);
            }
            if (seen.find(currentUglyNumber * 5) == seen.end()) {
                minHeap.push(currentUglyNumber * 5);
                seen.insert(currentUglyNumber * 5);
            }
        }
    
        return static_cast<int>(currentUglyNumber);
    }
};