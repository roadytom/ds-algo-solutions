package leetcode.stonegameI877;

import java.util.Arrays;

public class Solution2 {
    public boolean stoneGame(int[] piles) {
        final int N = piles.length;
        // at most alice and bob score difference
        boolean aliceScore = true;
        int[][] dp = new int[N][N];
        for (int start = N - 1; start >= 0; start--) {
            for (int end = start; end < N; end++) {
                if (start == end) {
                    dp[start][end] -= piles[start];
                    aliceScore = true;
                } else {
                    if (aliceScore) {
                        dp[start][end] = Math.max(piles[start] + dp[start + 1][end], piles[end] + dp[start][end - 1]);
                    } else {
                        dp[start][end] = Math.min(-piles[start] + dp[start + 1][end], -piles[end] + dp[start][end - 1]);
                    }
                    aliceScore = !aliceScore;
                }
            }
        }
        Arrays.stream(dp)
                .forEach(row -> System.out.println(Arrays.toString(row)));
        return dp[0][N - 1] > 0;
    }

    public static void main(String[] args) {
        System.out.println(new Solution2().stoneGame(new int[]{5, 3, 4, 5}));
    }
}
