package leetcode.java.heap.meetingrooms.I;

import java.util.Arrays;
import java.util.Comparator;

public class Solution1 {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < intervals.length - 1; i++) {
            int currEnd = intervals[i][1];
            int nextStart = intervals[i + 1][0];
            if (nextStart < currEnd) {
                return false;
            }
        }
        return true;
    }
}
