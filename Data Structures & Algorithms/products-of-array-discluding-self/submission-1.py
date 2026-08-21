class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p = 1
        result = []
        count_0 = 0
        for i in nums:
            if i != 0:
                p *= i
            else:
                count_0 += 1
        if count_0 == 1:
            for i in nums:
                if i == 0:
                    result.append(p)
                else:
                    result.append(0)
        else:
            if count_0 > 1:
                for i in nums:
                    result.append(0)
            else:
                for i in nums:
                    result.append(int(p/i))
        return result