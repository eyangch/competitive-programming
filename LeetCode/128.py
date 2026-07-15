class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        adjacency_list: dict[int, list[int]] = {x: [] for x in nums}
        for num in adjacency_list:
            for i in [-1, 1]:
                if num + i in adjacency_list:
                    adjacency_list[num].append(i)
        
        visited: set[int] = set()
        ans: int = 0
        for x in adjacency_list:
            if x in visited:
                continue
            cur_size: int = 1
            visited.add(x)
            for i in [-1, 1]:
                cur_num: int = x
                while i in adjacency_list[cur_num]:
                    cur_num += i
                    visited.add(cur_num)
                cur_size += (cur_num - x) * i
            ans = max(ans, cur_size)
        
        return ans