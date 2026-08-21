from collections import Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        final = []
        vis = set()
        for i in range(len(strs)):
            if i in vis:
                continue
            counter = Counter(strs[i])
            anagram_group = [strs[i]]
            vis.add(i)
            for j in range(i+1, len(strs)):
                if j not in vis and Counter(strs[j]) == counter:
                    anagram_group.append(strs[j])
                    vis.add(j)
            final.append(anagram_group)
        return final