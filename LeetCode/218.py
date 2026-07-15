import heapq

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        start_pos: dict[int, int] = {}
        end_pos: dict[int, int] = {}
        for i in range(len(buildings)):
            start_x: int = buildings[i][0]
            end_x: int = buildings[i][1]
            if start_x not in start_pos:
                start_pos[start_x] = []
            if end_x not in end_pos:
                end_pos[end_x] = []
            start_pos[start_x].append(i)
            end_pos[end_x].append(i)
        x_pos: list[int] = list(sorted(set(start_pos.keys()).union(set(end_pos.keys()))))
        ans: list[list[int]] = []
        previous_height: int = 0
        pq: list[int] = [0]
        delete_queue: dict[int, int] = {}
        for x in x_pos:
            if x in start_pos:
                for i in start_pos[x]:
                    heapq.heappush(pq, -buildings[i][2])
            if x in end_pos:
                for i in end_pos[x]:
                    h = -buildings[i][2]
                    if h not in delete_queue:
                        delete_queue[h] = 0
                    delete_queue[h] += 1
            while len(pq) > 0 and pq[0] in delete_queue and delete_queue[pq[0]] > 0:
                delete_queue[pq[0]] -= 1
                heapq.heappop(pq)
            if len(pq) > 0 and -pq[0] != previous_height:
                ans.append([x, -pq[0]])
                previous_height = -pq[0]
        return ans
