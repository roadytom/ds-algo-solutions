class SegmentTree:
    def __init__(self, arr):
        self.arr_length = len(arr)
        self.tree_length = 4 * self.arr_length
        self.tree = [0] * self.tree_length
        self.build_tree(arr)

    def build_tree(self, arr):
        def do_build_tree(idx, segment_left, segment_right):
            if segment_left == segment_right:
                self.tree[idx] = arr[segment_left]
                return
            mid = (segment_left + segment_right) // 2
            do_build_tree(2 * idx + 1, segment_left, mid)
            do_build_tree(2 * idx + 2, mid + 1, segment_right)
            self.tree[idx] = self.tree[2 * idx + 1] + self.tree[2 * idx + 2]

        do_build_tree(0, 0, self.arr_length - 1)

    def query(self, query_left, query_right):
        def do_query(idx, segment_left, segment_right, left, right):
            if segment_right < left or segment_left > right:
                return 0
            if left <= segment_left and segment_right <= right:
                return self.tree[idx]
            mid = (segment_left + segment_right) // 2
            left_result = do_query(2 * idx + 1, segment_left, mid, left, right)
            right_result = do_query(
                2 * idx + 2, mid + 1, segment_right, left, right)
            return left_result + right_result

        return do_query(0, 0, self.arr_length - 1, query_left, query_right)

    def update(self, idx, new_val):
        def do_update(tree_idx, seg_left, seg_right, idx, new_val):
            if seg_left == seg_right:
                self.tree[tree_idx] = new_val
                return
            mid = (seg_left + seg_right) // 2
            if idx <= mid:
                do_update(2 * tree_idx + 1, seg_left, mid, idx, new_val)
            else:
                do_update(2 * tree_idx + 2, mid + 1, seg_right, idx, new_val)
            self.tree[tree_idx] = self.tree[2 * tree_idx + 1] + \
                                  self.tree[2 * tree_idx + 2]

        do_update(0, 0, self.arr_length - 1, idx, new_val)
