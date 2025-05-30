package leetcode.java.heap.slidingwindowmedian;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * SIMPLE SORTING SOLUTION
 * NOT OPTIMAL
 * TIME COMPLEXITY: O(n * k * log(k))
 */
public class Solution1 {
    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] answer = new double[nums.length - k + 1];
        List<Integer> window = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            window.add(nums[i]);
        }
        answer[0] = findMedian(window);
        int answerIndex = 1;
        int arrayIndex = k;
        while (arrayIndex < nums.length) {
            window.add(nums[arrayIndex++]);
            window.remove(0);
            answer[answerIndex++] = findMedian(window);
        }
        return answer;
    }

    private double findMedian(List<Integer> window) {
        var sortedList = window.stream().sorted().toList();
        return sortedList.size() % 2 == 1 ? sortedList.get(sortedList.size() / 2) : (1D * sortedList.get(sortedList.size() / 2) + sortedList.get(sortedList.size() / 2 - 1)) / 2;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution1().medianSlidingWindow(new int[]{1, 3, -1, -3, 5, 3, 6, 7}, 3)));
    }
}
