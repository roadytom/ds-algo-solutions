package leetcode.java.contest.weekly.contest388.maximizehappiness3075;

import java.util.Arrays;

public class Solution1 {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int decr = 0;
        long sum = 0;
        int index = happiness.length - 1;
        for (int i = 0; i < k; i++) {
            int curr = happiness[index] - decr;
            if (curr == 0) {
                break;
            }
            sum += curr;
            decr++;
            index--;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().maximumHappinessSum(new int[]{12, 1, 42}, 3));
    }
}
