class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        totalOnes = sum(nums)
        
        # Edge cases
        if totalOnes == 0 or totalOnes == n:
            return 0
        
        onesInWindow = sum(nums[:totalOnes])
        maxOnesInWindow = onesInWindow
        
        # Slide the window and update max
        for i in range(n):
            onesInWindow = onesInWindow - nums[i] + nums[(i + totalOnes) % n]
            maxOnesInWindow = max(maxOnesInWindow, onesInWindow)
        
        return totalOnes - maxOnesInWindow