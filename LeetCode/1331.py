class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        mp = {z: i for i, z in enumerate(sorted(set(arr)))}
        return [mp[z]+1 for z in arr]
