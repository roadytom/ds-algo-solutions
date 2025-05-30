from collections import Counter


class SegmentCountTree:
    def __init__(self, max_num=1000):
        self.length = (max_num + 1)
        self.segment_tree = [0] * (4 * self.length)

    def range_sum(self, left_query, right_query):
        return self._range_sum(0, 0, self.length - 1, left_query, right_query)

    def _range_sum(self, segment_tree_idx, segment_left, segment_right, left_query, right_query):
        if left_query > right_query:
            return 0
        if segment_left == left_query and segment_right == right_query:
            return self.segment_tree[segment_tree_idx]
        mid = (segment_left + segment_right) // 2
        left_segment_sum = self._range_sum(self.get_left_child_idx(segment_tree_idx), segment_left, mid, left_query,
                                           min(mid, right_query))
        right_segment_sum = self._range_sum(self.get_right_child_idx(segment_tree_idx), mid + 1, segment_right,
                                            max(mid + 1, left_query),
                                            right_query)
        return left_segment_sum + right_segment_sum

    def update(self, idx, new_val=1):
        self.range_update(0, 0, self.length - 1, idx, new_val)

    def range_update(self, segment_tree_idx, segment_left, segment_right, idx, new_val):
        if segment_left == segment_right:
            self.segment_tree[segment_tree_idx] += new_val
            return

        mid = (segment_left + segment_right) // 2
        if idx <= mid:
            self.range_update(self.get_left_child_idx(segment_tree_idx), segment_left, mid, idx, new_val)
        else:
            self.range_update(self.get_right_child_idx(segment_tree_idx), mid + 1, segment_right, idx, new_val)
        self.segment_tree[segment_tree_idx] = self.get_left_child(segment_tree_idx) + self.get_right_child(
            segment_tree_idx)

    @staticmethod
    def get_left_child_idx(idx):
        return 2 * idx + 1

    @staticmethod
    def get_right_child_idx(idx):
        return 2 * idx + 2

    def get_left_child(self, idx):
        return self.segment_tree[self.get_left_child_idx(idx)]

    def get_right_child(self, idx):
        return self.segment_tree[self.get_right_child_idx(idx)]


class Solution:
    def countGoodTriplets(self, arr, a, b, c):
        n = len(arr)
        max_num = max(arr)
        right_sg_tree = SegmentCountTree(max(arr))
        for element in arr[2:]:
            right_sg_tree.update(element)

        counter = Counter()
        counter[arr[0]] += 1

        print(right_sg_tree.segment_tree)
        ans = 0
        for j in range(1, n - 1):
            mid = arr[j]
            left_i = max(0, mid - a)
            right_i = min(mid + a, max_num)
            left_k = max(0, mid - b)
            right_k = min(mid + b, max_num)
            for vali in range(left_i, right_i + 1):
                if counter[vali] == 0:
                    continue
                new_left_k = max(left_k, vali - c)
                new_right_k = min(right_k, vali + c)
                if new_left_k <= new_right_k:
                    print(new_left_k, new_right_k)
                    print(right_sg_tree.range_sum(new_left_k, new_right_k))
                    ans += right_sg_tree.range_sum(new_left_k, new_right_k) * counter[vali]
            right_sg_tree.update(arr[j + 1], -1)
            counter[arr[j]] += 1
            print(right_sg_tree.segment_tree)

        return ans


print(Solution().countGoodTriplets([3, 0, 1, 1, 9, 7], 7, 2, 3))
