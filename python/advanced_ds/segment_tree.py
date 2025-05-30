class SegmentSumTree:
    def __init__(self, arr):
        self.length = len(arr)
        self.segment_tree = [0] * (4 * self.length)
        self.build_segment_sum_tree(arr)

    def build_segment_sum_tree(self, arr):
        def build(idx, left, right):
            if left == right:
                self.segment_tree[idx] = arr[left]
                return
            mid = (left + right) // 2
            build(self.get_left_child_idx(idx), left, mid)
            build(self.get_right_child_idx(idx), mid + 1, right)
            # change operations here
            self.segment_tree[idx] = self.get_left_child(idx) + self.get_right_child(idx)

        build(0, 0, len(arr) - 1)

    def range_sum(self, idx, left, right, queried_left, queries_right):
        if queried_left > queries_right:
            return 0
        if left == queried_left and right == queries_right:
            return self.segment_tree[idx]
        mid = (left + right) // 2
        left_segment_sum = self.range_sum(self.get_left_child_idx(idx), left, mid, queried_left,
                                          min(mid, queries_right))
        right_segment_sum = self.range_sum(self.get_right_child_idx(idx), mid + 1, right, max(mid + 1, queried_left),
                                           queries_right)
        return left_segment_sum + right_segment_sum

    def range_update(self, idx, left, right, pos, new_val):
        if left == right:
            self.segment_tree[pos] = new_val
            return

        mid = (left + right) // 2
        if pos <= mid:
            self.range_update(self.get_left_child_idx(idx), left, mid, pos, new_val)
        else:
            self.range_update(self.get_right_child_idx(idx), mid + 1, right, pos, new_val)
        self.segment_tree[idx] = self.get_left_child(idx) + self.get_right_child(idx)

    @staticmethod
    def get_left_child_idx(idx):
        left_child_idx = 2 * idx + 1
        return left_child_idx

    @staticmethod
    def get_right_child_idx(idx):
        left_child_idx = 2 * idx + 2
        return left_child_idx

    def get_left_child(self, idx):
        return self.segment_tree[self.get_left_child_idx(idx)]

    def get_right_child(self, idx):
        return self.segment_tree[self.get_right_child_idx(idx)]
