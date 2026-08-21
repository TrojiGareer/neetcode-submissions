class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}
        for i,x in enumerate(nums):
            dif = target - x
            if dif in prevMap:
                return [prevMap[dif], i]
            prevMap[x] = i
        return