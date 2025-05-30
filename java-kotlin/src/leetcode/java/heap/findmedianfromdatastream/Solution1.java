package leetcode.java.heap.findmedianfromdatastream;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * O(n * log(n))
 */
public class Solution1 {
    static class MedianFinder {
        List<Integer> list;

        public MedianFinder() {
            list = new ArrayList<>();
        }

        public void addNum(int num) {
            if (list.isEmpty()) {
                list.add(num);
            } else {
                int index = Collections.binarySearch(list, num);
                if (index < 0) {
                    index = -index - 1;
                }
                if (index == list.size()) {
                    list.add(num);
                } else {
                    list.add(index, num);
                }
            }
        }

        public double findMedian() {
            if (list.size() % 2 == 0) {
                return 1D * (list.get(list.size() / 2 - 1) + list.get(list.size() / 2)) / 2;
            } else {
                return list.get(list.size() / 2);
            }
        }
    }

    public static void main(String[] args) {
        var finder = new MedianFinder();
        finder.addNum(-1);
        finder.addNum(-2);
        System.out.println(finder.findMedian());
    }
}
