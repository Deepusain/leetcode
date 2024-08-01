class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans =0
        for i in details:
            # int(string) s to i formula
            # string[11:13] substring from 11 to 12
            if int(i[11:13])>60:
                ans+=1
        return ans