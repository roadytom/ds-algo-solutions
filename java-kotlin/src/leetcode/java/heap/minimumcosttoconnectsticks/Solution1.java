package leetcode.java.heap.minimumcosttoconnectsticks;

import java.util.PriorityQueue;

public class Solution1 {
    public int connectSticks(int[] sticks) {
        if (sticks.length <= 1) {
            return 0;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int stick : sticks) {
            pq.offer(stick);
        }
        int cost = 0;
        while (pq.size() > 1) {
            int f = pq.poll();
            int s = pq.poll();
            cost += f + s;
            pq.offer(f + s);
        }
        return cost;
    }
}
