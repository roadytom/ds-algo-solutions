package leetcode.java.heap.takegiftsfromtherichestpile;

import java.util.PriorityQueue;
import java.util.Queue;

public class Solution1 {
  public long pickGifts(int[] gifts, int k) {
    if (gifts.length == 0) {
      return 0;
    }
    Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
    for (int gift : gifts) {
      pq.offer(gift);
    }
    for (int i = 0; i < k; i++) {
      int gift = pq.poll();
      pq.offer((int) Math.sqrt(gift));
    }
    long sum = 0;
    while (!pq.isEmpty()) {
      sum += pq.poll();
    }
    return sum;
  }
}
