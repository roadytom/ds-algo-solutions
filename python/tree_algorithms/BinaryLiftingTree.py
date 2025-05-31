from collections import deque
from functools import wraps
from math import log2


def require_built(method):
    @wraps(method)
    def wrapper(self, *args, **kwargs):
        if not self._built:
            raise Exception("Tree not built. Call build() before calling")
        return method(self, *args, **kwargs)

    return wrapper


class BinaryLiftingTree:
    def __init__(self, nodes_count):
        self.nodes_count = nodes_count
        self.max_log = int(log2(nodes_count)) + 1
        self.up: list[list[int]] = [[-1] * self.max_log for _ in range(nodes_count)]
        self.depth: list[int] = [0] * nodes_count
        self.tree: list[list[int]] = [[] for _ in range(nodes_count)]
        self._built = False

    def add_edge(self, a: int, b: int):
        self.tree[a].append(b)
        self.tree[b].append(a)
        self._built = False

    def build(self, root=0, recursive=True):
        if recursive:
            self.dfs(root, -1)
        else:
            self.dfs_iterative(root)
        self._built = True


    def dfs(self, node, parent):
        for child in self.tree[node]:
            if child == parent:
                continue
            self.depth[child] = self.depth[node] + 1
            self.up[child][0] = node
            for log in range(1, self.max_log):
                if self.up[child][log - 1] != -1:
                    self.up[child][log] = self.up[self.up[child][log - 1]][log - 1]
            self.dfs(child, node)

    def dfs_iterative(self, root):
        stack = deque()
        stack.append((root, -1))
        while stack:
            node, parent = stack.pop()
            for child in self.tree[node]:
                if child == parent:
                    continue
                self.depth[child] = self.depth[node] + 1
                self.up[child][0] = node
                for log in range(1, self.max_log):
                    if self.up[child][log - 1] != -1:
                        self.up[child][log] = self.up[self.up[child][log - 1]][log - 1]
                stack.append((child, node))

    @require_built
    def get_kth_ancestor(self, node, k):
        for i in range(self.max_log):
            if k & (1 << i) != 0:
                node = self.up[node][i]
                if node == -1:
                    return -1
        return node

    @require_built
    def get_lca(self, first_node, second_node):
        if self.depth[first_node] > self.depth[second_node]:
            first_node, second_node = second_node, first_node
        diff = self.depth[second_node] - self.depth[first_node]
        second_node = self.get_kth_ancestor(second_node, diff)
        if first_node == second_node:
            return first_node
        for log in range(self.max_log - 1, -1, -1):
            if self.up[first_node][log] != -1 and self.up[first_node][log] != self.up[second_node][log]:
                first_node = self.up[first_node][log]
                second_node = self.up[second_node][log]
        return self.up[first_node][0]

    @require_built
    def get_distance(self, first_node, second_node):
        lca_node = self.get_lca(first_node, second_node)
        return self.depth[first_node] + self.depth[second_node] - 2 * self.depth[lca_node]
