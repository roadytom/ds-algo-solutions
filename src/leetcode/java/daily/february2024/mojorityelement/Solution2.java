package leetcode.java.daily.february2024.mojorityelement;

/**
 * Boyer-Moore Majority Voting Algorithm
 * the main idea is if element is majority,
 * count of majority element, difference with
 * other elements must positive
 */
public class Solution2 {
    public int majorityElement(int[] nums) {
        int count = 0;
        int element = -1;
        for (int num : nums) {
            if (count == 0) {
                element = num;
                count = 1;
            } else if (element == num) {
                count++;
            } else {
                count--;
            }
        }
        if (count == 0) {
            return -1;
        }
        // check if element is DO exist
        // because algorithm gives possible
        // value for majority if it exists
        count = 0;
        for (int num : nums) {
            if (num == element) {
                count++;
            }
        }
        if (count > nums.length / 2) {
            return element;
        }
        return -1;
    }
}
