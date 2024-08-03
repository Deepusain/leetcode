class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target.sort()
        arr.sort()
        n,m = len(target),len(arr)
        if n != m:
            return False
        for i in range(n):
            if target[i] != arr[i]:
                return False
        return True