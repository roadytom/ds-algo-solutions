from typing import List


class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        tree: List[List[int]] = [[] for _ in range(n)]
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)
        answer = [0] * n
        subtree_count = [1] * n

        def dfs_post_order(node, parent):
            for adj in tree[node]:
                if adj == parent:
                    continue
                dfs_post_order(adj, node)
                subtree_count[node] += subtree_count[adj]
                answer[node] += answer[adj] + subtree_count[adj]

        dfs_post_order(0, -1)

        def dfs_pre_order(node, parent):
            for adj in tree[node]:
                if adj == parent:
                    continue
                answer[adj] = answer[node] + (n - subtree_count[adj]) - subtree_count[adj]
                dfs_pre_order(adj, node)

        dfs_pre_order(0, -1)
        return answer
