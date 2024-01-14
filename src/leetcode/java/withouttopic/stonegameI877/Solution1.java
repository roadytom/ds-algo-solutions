package leetcode.java.withouttopic.stonegameI877;

import java.util.Arrays;

/**
 * solution 1 with dynamic programming
 * most verbose solution
 * I tried to mimic real world scenario
 * Time Complexity: O(N*N), Space Complexity: O(N*N)
 */
public class Solution1 {
    public boolean stoneGame(int[] piles) {
        final int N = piles.length;
        int[][][] dp = new int[N][N][3];
        for (int start = N - 1; start >= 0; start--) {
            for (int end = start; end < N; end++) {
                if (start == end) {
                    dp[start][end] = new int[]{-1, -1, piles[start]};
                } else if (start + 1 == end) {
                    if (piles[start] > piles[end]) {
                        dp[start][end] = new int[]{end, end, piles[start]};
                    } else dp[start][end] = new int[]{start, start, piles[end]};
                } else {
                    int firstChoice = piles[start] + dp[dp[start + 1][end][0]][dp[start + 1][end][1]][2];
                    int secondChoice = piles[end] + dp[dp[start][end - 1][0]][dp[start][end - 1][1]][2];
                    if (firstChoice > secondChoice) {
                        dp[start][end] = new int[]{start + 1, end, firstChoice};
                    } else {
                        dp[start][end] = new int[]{start, end - 1, secondChoice};
                    }
                }
                System.out.println(start + " " + end + " " + Arrays.toString(dp[start][end]));
            }
        }
        //  0->3,1->7,2->2,2->3
//        for (int[][] ints : dp) {
//            System.out.println(Arrays.deepToString(ints));
//        }
        return dp[0][N - 1][2] > dp[dp[0][N - 1][0]][dp[0][N - 1][1]][2];
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().stoneGame(new int[]{3, 7, 2, 3}));
    }
}
/**
 * 1 2 4 5 6 7 2 5
 * 4 5 6 7 2 5
 * 2 4 5 6 7 2
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 * <p>
 * 4 5 6 6
 */

/**
 4 5 6 6
 */