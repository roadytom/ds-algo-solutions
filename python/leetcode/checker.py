class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        curr_start, curr_end = intervals[0][0], intervals[0][1]
        merged_intervals = []
        for start, end in intervals:
            if curr_end >= start:
                curr_end = max(curr_end, end)
                continue
            merged_intervals.append((curr_start, curr_end))
            curr_start, curr_end = start, end
        merged_intervals.append((curr_start, curr_end))
        return merged_intervals