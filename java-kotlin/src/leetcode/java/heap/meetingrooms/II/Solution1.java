package leetcode.java.heap.meetingrooms.II;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution1 {
    public int minMeetingRooms(int[][] intervals) {
        PriorityQueue<int[]> rooms = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        for (int[] interval : intervals) {
            int currStart = interval[0];
            if (rooms.isEmpty()) {
                rooms.offer(interval);
            } else {
                int earliestEnd = rooms.peek()[1];
                if (earliestEnd <= currStart) {
                    rooms.poll();
                }
                rooms.offer(interval);
            }

        }
        return rooms.size();
    }
}
