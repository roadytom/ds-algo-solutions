package leetcode.java.divideandconquer.kthlargestelementinarray;


/**
 * Hoare's Partition Algorithm
 * {3, 2, 1, 5, 4}
 * {2, 1, 4, 5}
 */

public class Solution2 {
    public int findKthLargest(int[] nums, int k) {
        int left = 0, right = nums.length - 1;
        int searchIndex = nums.length - k;
        // I need 2nd index
        while (left < right) {
            int foundIndex = quickSelect(left, right, nums);
//      System.out.println(Arrays.toString(nums));
            // we got 1 here
            if (searchIndex > foundIndex) {
                left = foundIndex + 1;
            } else {
                right = foundIndex;
            }
        }
        return nums[left];
    }

    private int quickSelect(int left, int right, int[] nums) {
        int i = left - 1;
        int j = right + 1;
        int pivot = nums[left];
        while (true) {
            do {
                i++;
            } while (nums[i] < pivot);

            do {
                j--;
            } while (nums[j] > pivot);
            if (i >= j) {
                return j;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[]{4, 4, 5, 7, 4, 9, 2};
        /**
         * 2, 4, 5, 7,| 10, 9, 8
         */
//    System.out.println(new Solution2().quickSelect(0, arr.length - 1, arr));
        System.out.println(new Solution2().findKthLargest(new int[]{3, 1, 2, 4}, 2));
//    System.out.println(Arrays.toString(arr));
    }
}
