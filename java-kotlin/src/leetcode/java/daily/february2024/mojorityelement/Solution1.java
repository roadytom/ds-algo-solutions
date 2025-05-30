package leetcode.java.daily.february2024.mojorityelement;

/**
 * Any bit that occurred more
 * than n / 2, than we are sure
 * it should be part of majority
 * element. Because, we have only
 * one majority element, and only
 * its bits are more than n / 2
 */
public class Solution1 {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int majorityElement = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int count = 0;
            for (int num : nums) {
                if ((num & bit) != 0) {
                    count++;
                }
            }
            if (count > n / 2) {
                majorityElement |= bit;
            }
        }
        return majorityElement;
    }
}
