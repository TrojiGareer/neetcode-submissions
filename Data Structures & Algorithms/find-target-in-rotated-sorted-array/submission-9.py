class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2

            if target == nums[mid]:
                return mid

            if nums[l] <= nums[mid]: # left portion
                if target <= nums[mid]:
                    if target < nums[l]:
                        l = mid + 1
                    else:
                        r = mid - 1
                else:
                    l = mid + 1
            else:
                if target >= nums[mid]:
                    if target <= nums[r]:
                        l = mid + 1
                    else:
                        r = mid - 1
                else:
                    r = mid - 1
        return -1
            