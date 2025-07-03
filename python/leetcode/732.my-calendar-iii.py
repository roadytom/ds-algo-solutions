#
# @lc app=leetcode id=732 lang=python3
#
# [732] My Calendar III
#

# @lc code=start
class MyCalendarThree:

    def __init__(self):
        self.tree = defaultdict(int)
        self.lazy = defaultdict(int)
        self.maxs = defaultdict(int)
        self.events = defaultdict(int)

    def update(self, tree_idx, seg_left, seg_right, left, right, addend):
        if seg_left > right or seg_right < left:
            return
        if left <= seg_left and seg_right <= right:
            self.tree[tree_idx] += addend
            self.lazy[tree_idx] += addend
        else:
            mid = (seg_left + seg_right) // 2
            self.update(2 * tree_idx + 1, seg_left, mid, left, right, addend)
            self.update(
                2 * tree_idx + 2, mid + 1, seg_right, left, right, addend)
            # curr max number of events = max of max [L, mid] and [mid + R] + all events between [L, R]
            self.tree[tree_idx] = self.lazy[tree_idx] + max(
                self.tree[2 * tree_idx + 1], self.tree[2 * tree_idx + 2])

    def update_lazy(self, tree_idx, seg_left, seg_right, query_left, query_right, val):
        if seg_right < query_left or query_right < seg_left:
            return
        if query_left <= seg_left and seg_right <= query_right:
            self.tree[tree_idx] += val
            self.lazy[tree_idx] += val
        else:
            self._push(tree_idx)
            mid = (seg_left + seg_right) // 2
            self.update_lazy(2 * tree_idx + 1, seg_left,
                             mid, query_left, query_right, val)
            self.update_lazy(2 * tree_idx + 2, mid + 1,
                             seg_right, query_left, query_right, val)
            self.tree[tree_idx] = max(
                self.tree[2 * tree_idx + 1], self.tree[2 * tree_idx + 2])

    def query_lazy(self, tree_idx, seg_left, seg_right, query_left, query_right):
        if seg_right < query_left or query_right < seg_left:
            return float("-inf")
        if query_left <= seg_left and seg_right <= query_right:
            return self.tree[tree_idx]
        else:
            self._push(tree_idx)
            mid = (seg_left + seg_right) // 2
            left = self.query(2 * tree_idx + 1, seg_left,
                              mid, query_left, query_right)
            right = self.query(2 * tree_idx + 2, mid + 1,
                               seg_right, query_left, query_right)
            return max(left, right)

    def _push(self, tree_idx):
        self.tree[2 * tree_idx + 1] += self.lazy[tree_idx]
        self.lazy[2 * tree_idx + 1] += self.lazy[tree_idx]
        self.tree[2 * tree_idx + 2] += self.lazy[tree_idx]
        self.lazy[2 * tree_idx + 2] += self.lazy[tree_idx]
        self.lazy[tree_idx] = 0

    def book(self, start_time: int, end_time: int) -> int:
        self.update_lazy(0, 0, 10 ** 9, start_time, end_time - 1, 1)
        return self.query_lazy(0, 0, 10 ** 9, 0, 10 ** 9)

# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)
# @lc code=end
