package leetcode.stonegame1140;

import java.util.Arrays;

public class Solution1 {
    int[] subArraySum;
    int[] piles;
    int[][][] dp;

    public int stoneGameII(int[] piles) {
        final int N = piles.length;
        this.subArraySum = new int[N + 1];
        this.piles = piles;
        for (int i = 1; i <= N; i++) {
            subArraySum[i] = subArraySum[i - 1] + piles[i - 1];
        }
        dp = new int[2][N + 1][N + 1];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 0; k <= N; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solver(0, N - 1, 1, true);
    }

    private int solver(int start, int end, int m, boolean aliceTurn) {
        if (end - start + 1 <= 2 * m) {
            return aliceTurn ? subArraySum[end + 1] - subArraySum[start] : 0;
        }
        if (dp[(aliceTurn ? 0 : 1)][start][m] != -1) {
            return dp[(aliceTurn ? 0 : 1)][start][m];
        }
        int getInitialTakenScore = 0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= 2 * m; i++) {
            getInitialTakenScore += piles[start + i - 1];
            if (aliceTurn) {
                max = Math.max(max, getInitialTakenScore + solver(start + i, end, Math.max(i, m), false));
            } else {
                min = Math.min(min, solver(start + i, end, Math.max(i, m), true));
            }
        }

        return dp[(aliceTurn ? 0 : 1)][start][m] = aliceTurn ? max : min;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().stoneGameII(new int[]{7, 5, 9, 9, 9, 9, 5, 1, 8, 6}));
    }

}
