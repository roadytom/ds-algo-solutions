from typing import List


class SegmentTree:
    def __init__(self, elements_count):
        self.size = elements_count
        self.tree = [0] * (4 * elements_count)

    def query(self, query_left, query_right, tree_idx=0, segment_left=0, segment_right=None):
        if segment_right is None:
            segment_right = self.size - 1
        if segment_right < query_left or query_right < segment_left:
            return 0
        if query_left <= segment_left and segment_right <= query_right:
            return self.tree[tree_idx]
        mid = (segment_left + segment_right) // 2
        return self.query(query_left, query_right, tree_idx * 2 + 1, segment_left, mid) + \
            self.query(query_left, query_right, tree_idx * 2 + 2, mid + 1, segment_right)

    def update(self, idx, change, tree_idx=0, segment_left=0, segment_right=None):
        if segment_right is None:
            segment_right = self.size - 1
        if segment_left == segment_right:
            self.tree[tree_idx] += change
            return
        mid = (segment_left + segment_right) // 2
        if idx <= mid:
            self.update(idx, change, tree_idx * 2 + 1, segment_left, mid)
        else:
            self.update(idx, change, tree_idx * 2 + 2, mid + 1, segment_right)
        self.tree[tree_idx] = self.tree[tree_idx * 2 + 1] + self.tree[tree_idx * 2 + 2]


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # path compression
        sorted_unique_elements = sorted(set(nums))
        coordinate_map = {num: idx for idx, num in enumerate(sorted_unique_elements)}
        max_idx = len(coordinate_map) - 1
        segment_tree = SegmentTree(len(sorted_unique_elements))
        result = []
        print(coordinate_map)
        for num in reversed(nums):
            idx = coordinate_map[num]
            result.append(segment_tree.query(0, idx - 1))
            segment_tree.update(idx, +1)
        return result[::-1]


print(Solution().countSmaller([5, 2, 6, 1]))
