class Solution(object):
    def scoreOfString(self, s):
        """
        :type s: str
        :rtype: int
        """
        total =0
        for i in range (0,len(s)-1):
            total += abs(ord(s[i]) - ord(s[i + 1]))
        return total