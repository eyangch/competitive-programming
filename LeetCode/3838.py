class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        res = []
        for word in words:
            weight = 0
            for c in word:
                weight += weights[ord(c) - ord('a')]
            res.append(chr((25 - weight % 26) + ord('a')))
        return ''.join(res)