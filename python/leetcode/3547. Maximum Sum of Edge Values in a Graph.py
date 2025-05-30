from collections import defaultdict, deque
from typing import List


class Solution:
    def maxScore1(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)

        def bfs(i):
            queue = deque([i])
            seen[i] = True
            nodes = []
            nodes.append(i)
            while queue:
                pop = queue.pop()
                for neighbor in graph[pop]:
                    if not seen[neighbor]:
                        seen[neighbor] = True
                        queue.appendleft(neighbor)
                        nodes.append(neighbor)
            return nodes

        def calc(l, r, is_cycle):
            d = deque([r, r])
            res = 0
            for a in range(r - 1, l - 1, -1):
                v = d.popleft()
                res += v * a
                d.append(a)
            return res + d[0] * d[1] * is_cycle

        circles = []
        lines = []
        seen = [False] * n
        for i in range(n):
            if not seen[i]:
                comp = bfs(i)
                if all(len(graph[node]) == 2 for node in comp):
                    circles.append(len(comp))
                elif len(comp) > 1:
                    lines.append(len(comp))
        res = 0
        lines.sort()
        print(circles)
        print(lines)
        for k in circles:
            res += calc(n - k + 1, n, 1)
            n -= k
        for k in lines:
            res += calc(n - k + 1, n, 0)
            n -= k
        return res

    def maxScore2(self, n: int, edges: List[List[int]]) -> int:
        G = defaultdict(list)
        for i, j in edges:
            G[i].append(j)
            G[j].append(i)

        def get_comp(i):
            bfs = [i]
            seen[i] = True
            for i in bfs:
                for j in G[i]:
                    if not seen[j]:
                        seen[j] = True
                        bfs.append(j)
            return bfs

        C = []
        L = []
        seen = [False] * n
        for i in range(n):
            if not seen[i]:
                comp = get_comp(i)
                if all(len(G[x]) == 2 for x in comp):
                    C.append(len(comp))
                elif len(comp) > 1:
                    L.append(len(comp))

        def calc(l, r, is_cycle):
            d = deque([r, r])
            res = 0
            for a in range(r - 1, l - 1, -1):
                v = d.popleft()
                res += v * a
                d.append(a)
            return res + d[0] * d[1] * is_cycle

        res = 0
        L = sorted(L)[::-1]
        print(C)
        print(L)
        for k in C:
            res += calc(n - k + 1, n, 1)
            n -= k
        for k in L:
            res += calc(n - k + 1, n, 0)
            n -= k
        return res


solution = Solution()
n = 20
edges = [[18, 14], [12, 18], [12, 9], [1, 9], [7, 1], [5, 7], [0, 13], [6, 0], [6, 16], [15, 16], [10, 19], [17, 4], [2, 4], [2, 3], [3, 8]]
print(solution.maxScore1(n, edges))
print(solution.maxScore2(n, edges))
