class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        right = left =0
        size = len(nums)
        max_len =0
        freq_map =  defaultdict(int)

        while right<size:
            freq_map[nums[right]]+=1
            while freq_map[nums[right]]>k:
                freq_map[nums[left]]-=1
                left +=1

            max_len=max(max_len,(right-left+1))
            right +=1
        return max_len