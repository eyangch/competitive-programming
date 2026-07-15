class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        for i in range(len(tasks)):
            tasks[i][1] -= tasks[i][0]
        cost = 0
        tasks.sort(key=lambda x: x[1])
        for ac, mn in tasks:
            if cost < mn:
                cost = mn
            cost += ac
        return cost