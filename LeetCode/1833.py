class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        occ = [0] * (max(costs) + 1)
        for cost in costs:
            occ[cost] += 1
        cnt = 0
        for i in range(len(occ)):
            for j in range(occ[i]):
                if coins - i < 0:
                    return cnt
                coins -= i
                cnt += 1
        return cnt
