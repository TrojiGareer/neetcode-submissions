from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # print(Counter(nums))
        count = {}
        topKfreq = [[] for i in range(0, len(nums) + 1)]
        for n in nums:
            count[n] = 1 + count.get(n, 0)
        # print(count)
        for n, c in count.items():
            topKfreq[c].append(n)
        res = []
        print("TopKfreq", topKfreq)
        for i in range(len(topKfreq) - 1, 0, -1):
            
            for n in topKfreq[i]:
                print(n)
                res.append(n)
                if len(res) == k:
                    return res
        