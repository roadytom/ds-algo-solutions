@dataclass
class Node:
    def __init__(self, k):
        self.prod = 1 % k
        self.count = [0] * k


class SegmentTree:
    def __init__(self, arr, k):
        self.size = len(arr)
        self.tree_size = 4 * self.size
        self.tree = [None] * self.tree_size
        self.build_tree(0, 0, self.size - 1, arr, k)

    def build_tree(self, idx, seg_left, seg_right, arr, k):
        if seg_left == seg_right:
            node = Node(k)
            node.prod = arr[seg_left] % k
            node.count[arr[seg_left] % k] += 1
            self.tree[idx] = node
            return
        mid = (seg_left + seg_right) // 2
        self.build_tree(2 * idx + 1, seg_left, mid, arr, k)
        self.build_tree(2 * idx + 2, mid + 1, seg_right, arr, k)
        self.tree[idx] = self.merge(2 * idx + 1, 2 * idx + 2, k)

    def merge(self, left_idx, right_idx, k):
        left_child = self.tree[left_idx]
        right_child = self.tree[right_idx]
        node = Node(k)
        node.prod = (left_child.prod * right_child.prod) % k
        node.count = left_child.count[:]
        for rem in range(k):
            c = right_child.count[rem]
            result = (left_child.count * rem) % k
            node.count[result] += c
        return node


class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
