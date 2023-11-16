package algoexpert.medium.threenumbersort.sol3;

/**
 * Dutch National Flag algorithm
 */
public class Program {
    public int[] threeNumberSort(int[] nums, int[] order) {
        int low = 0; // Points to the current position for 0.
        int mid = 0; // Points to the current position for 1.
        int high = nums.length - 1; // Points to the current position for 2.

        while (mid <= high) {
            if (nums[mid] == order[0]) {
                // If the current element is 0, swap it with the element at the low pointer.
                swap(nums, low, mid);
                low++; // Increment low pointer.
                mid++; // Increment mid pointer.
            } else if (nums[mid] == order[1]) {
                // If the current element is 1, simply increment mid pointer.
                mid++;
            } else {
                // If the current element is 2, swap it with the element at the high pointer.
                swap(nums, mid, high);
                high--; // Decrement high pointer.
            }
        }
        return nums;
    }

    private void swap(int[] nums, int low, int mid) {
        int temp = nums[low];
        nums[low] = nums[mid];
        nums[mid] = temp;
    }
}
