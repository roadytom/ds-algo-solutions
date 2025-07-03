from typing import List


class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        tree = [[] for _ in range(n)]
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)
        answer = [0] * n
        subtree_count = [1] * n
        distance_sum = [0] * n

        def dfs_post_order(node, parent):
            for adj in tree[node]:
                if adj == parent:
                    continue
                dfs_post_order(adj, node)
                subtree_count[node] += subtree_count[adj]
                distance_sum[node] += distance_sum[adj] + subtree_count[adj]

        dfs_post_order(0, -1)
        answer[0] = subtree_count[0]

        def dfs_pre_order(node, parent):
            for adj in tree[node]:
                if adj == parent:
                    continue
                answer[node] = answer[parent] + subtree_count[parent] - subtree_count[node]
                dfs_pre_order(adj, node)

        return answer
