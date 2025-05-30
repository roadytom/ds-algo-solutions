package leetcode.java.heap.findmedianfromdatastream;

import java.util.Collections;
import java.util.PriorityQueue;

public class Solution2 {
    static class MedianFinder {
        // left half
        PriorityQueue<Integer> maxHeap;
        // right half
        PriorityQueue<Integer> minHeap;

        public MedianFinder() {
            // make it max heap
            maxHeap = new PriorityQueue<>(Collections.reverseOrder());
            minHeap = new PriorityQueue<>();
        }

        public void addNum(int num) {
            // if element is less than or equal to left-half max
            // than go to left half
            if (maxHeap.isEmpty() || maxHeap.peek() >= num) {
                maxHeap.offer(num);
            } else {
                minHeap.offer(num);
            }

            // keep both of them balanced
            // our rule is, left size should be
            // equal or 1 more element than right half
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.offer(maxHeap.poll());
            } else if (maxHeap.size() < minHeap.size()) {
                maxHeap.offer(minHeap.poll());
            }
        }


        public double findMedian() {
            if (maxHeap.isEmpty() && minHeap.isEmpty()) {
                throw new IllegalStateException("empty heap");
            }
            int size = minHeap.size() + maxHeap.size();

            if (size % 2 == 1) {
                return maxHeap.peek();
            } else {
                return (minHeap.peek() + maxHeap.peek()) / 2D;
            }
        }
    }

    public static void main(String[] args) {
        var finder = new MedianFinder();
        finder.addNum(1);
        finder.addNum(2);
        System.out.println(finder.findMedian());
        finder.addNum(3);
        System.out.println(finder.findMedian());
    }
}
