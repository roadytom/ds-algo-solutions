package leetcode.java.daily.february2024.furthestbuildingyoucanreach;

import java.util.PriorityQueue;

public class Solution1 {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>();
        int maxIndex = 0;
        for (int i = 0; i < heights.length; i++) {
            if (i == heights.length) {
                maxIndex = i;
                break;
            }
            if (heights[i] > heights[i + 1]) {
                continue;
            }
            int diff = heights[i + 1] - heights[i];
            if (diff > bricks) {
                // not possible to use bricks

            }
        }
        return 0;
    }
}
