package leetcode.shortestunsortedcontinuoussubarray581;

import java.util.Arrays;

/**
 * The provided code aims to find the shortest unsorted subarray within an array of integers nums.
 * It does so by creating a sorted version of the array and then comparing elements from the beginning and the end of both arrays to find the unsorted subarray.
 * Let's analyze the time complexity of this code:
 * 1. Sorting the Array: The line int[] sorted = Arrays.stream(nums).sorted().toArray(); sorts the nums array, which has a time complexity of O(n*log(n)), where 'n' is the length of the array.
 * 2. Finding the Left Boundary: The while loop, which is based on the left variable, compares elements from the beginning of the sorted and unsorted arrays. In the worst case, it needs to iterate through the entire array, so the time complexity is O(n).
 * 3. Finding the Right Boundary: Similarly, the while loop based on the right variable compares elements from the end of the arrays, with a worst-case time complexity of O(n).
 * 4. Returning the Result: The code returns right - left + 1, which is a constant-time operation, so its time complexity is O(1).
 * The overall time complexity of this code is determined by the most time-consuming part,
 * which is sorting the array in O(nlog(n)) time.
 * Therefore, the code's time complexity is O(nlog(n)).
 */
public class Solution1 {
    public int findUnsortedSubarray(int[] nums) {
        int[] sorted = Arrays.stream(nums).sorted().toArray();
        int left = 0;
        while (left < nums.length) {
            if (sorted[left] != nums[left]) {
                break;
            }
            left++;
        }
        int right = nums.length - 1;
        while (right >= 0) {
            if (sorted[right] != nums[right]) {
                break;
            }
            right++;
        }
        return (right < left) ? 0 : right - left + 1;
    }
}
