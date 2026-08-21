class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # p = 1
        # result = []
        # count_0 = 0
        # for i in nums:
        #     if i != 0:
        #         p *= i
        #     else:
        #         count_0 += 1
        # if count_0 == 1:
        #     for i in nums:
        #         if i == 0:
        #             result.append(p)
        #         else:
        #             result.append(0)
        # else:
        #     if count_0 > 1:
        #         for i in nums:
        #             result.append(0)
        #     else:
        #         for i in nums:
        #             result.append(int(p/i))
        result = []
        preffix = []
        p = 1
        for i in nums:
            p *= i
            preffix.append(p)
        suffix = []
        p = 1
        for i in range(len(nums) - 1, -1, -1):
            p *= nums[i]
            suffix.append(p)
        print(preffix, suffix)
        for i in range(len(nums)):
            if i == 0:
                result.append(suffix[len(suffix) - 2])
            else:
                if i == len(nums) - 1:
                    result.append(preffix[len(preffix) - 2])
                else:
                    result.append(preffix[i - 1] * suffix[len(suffix) - i - 2])
        return result