class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        left = right = ma_len=0
        size=len(s)
        freq_map={}
        while right<size:
            if s[right] not in freq_map:
                freq_map[s[right]]=0
            freq_map[s[right]] +=1
            while freq_map[s[right]]>2:
                freq_map[s[left]] -=1
                left+=1
            ma_len=max(ma_len,(right-left+1))
            right+=1
        
        return ma_len