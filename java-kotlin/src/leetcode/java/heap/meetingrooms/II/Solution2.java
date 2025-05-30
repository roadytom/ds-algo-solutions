package leetcode.java.heap.meetingrooms.II;

import java.util.Arrays;
import java.util.List;

public class Solution2 {
    public int minMeetingRooms(int[][] intervals) {
        List<Integer> starts = Arrays.stream(intervals)
                .map(x -> x[0])
                .sorted()
                .toList();
        List<Integer> ends = Arrays.stream(intervals)
                .map(x -> x[1])
                .sorted()
                .toList();

        int startPointer = 0, endPointer = 0;
        int room = 0;
        while (startPointer < starts.size()) {
            if (ends.get(endPointer) > starts.get(startPointer)) {
                room++;
            } else {
                endPointer++;
            }
            startPointer++;
        }
        return room;
    }
}
