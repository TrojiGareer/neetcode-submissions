import itertools
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        pairs = []
        for i in range(len(nums)):
            ok = 0
            target = -nums[i]
            j = i + 1
            k = len(nums) - 1
            while j < k and ok == 0:
                if nums[j] + nums[k] < target:
                    j += 1
                else:
                    if nums[j] + nums[k] > target:
                        k -= 1
                    else:
                        pairs.append([nums[i], nums[j], nums[k]])
                        j += 1
                        while nums[j] == nums[j - 1] and j < k:
                            j += 1
            if ok == 1:
                pairs.append([nums[i], nums[j], nums[k]])
        pairs.sort()
        pairs = list(pairs for pairs,_ in itertools.groupby(pairs))
        return pairs