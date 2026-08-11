class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        sum=nums[0]

        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]+1:
                sum+=nums[i]
            else :
                break
        
        s = set(nums)

        while sum in s:
            sum +=1
        
        return sum