from collections import Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # final = []
        # vis = set()
        # for i in range(0, len(strs)):
        #     if strs[i] in vis:
        #         continue
        #     counter = Counter(strs[i])
        #     anagram_group = []
        #     anagram_group.append(strs[i])
        #     vis.add(strs[i])
        #     for j in range(0, len(strs)):
        #         if j != i:
        #             if strs[j] not in vis and Counter(strs[j]) == counter:
        #                 anagram_group.append(strs[j])
        #                 vis.add(strs[j])
        #     final.append(anagram_group)
        # return final
        groups = defaultdict(list)
        for word in strs:
            key = tuple(sorted(word))   # cheia unică pentru anagrame
            groups[key].append(word)
        return list(groups.values())