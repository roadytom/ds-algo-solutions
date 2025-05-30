package leetcode.java.contest.weekly.contest388.appleredistribution3074;

import java.util.Arrays;
import java.util.PriorityQueue;

public class Solution1 {
    public int minimumBoxes(int[] apple, int[] capacity) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int c : capacity) {
            pq.offer(c);
        }
        int sum = Arrays.stream(apple).sum();
        int count = 0;
        while (sum > 0) {
            sum -= pq.poll();
            count++;
        }
        return count;
    }
}
