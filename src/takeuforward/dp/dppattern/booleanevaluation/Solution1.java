package takeuforward.dp.dppattern.booleanevaluation;

import java.util.Arrays;

public class Solution1 {
    private static final int MOD = 1_000_000_007;

    public static int evaluateExp(String exp) {
        final int n = exp.length();
        long[][][] memo = new long[n][n][2];
        for (long[][] row : memo) {
            Arrays.fill(row, new long[]{-1, -1});

        }
        return (int) dp(0, exp.length() - 1, exp, memo)[0];
    }

    /**
     * returns Key -> true count, Value -> false count
     *
     * @param l
     * @param r
     * @param exp
     * @return
     */
    private static long[] dp(int l, int r, String exp, long[][][] memo) {
        // BASE CASE:
        if (l == r) {
            if (exp.charAt(l) == 'T') {
                return new long[]{1, 0};
            } else if (exp.charAt(l) == 'F') {
                return new long[]{0, 1};
            }
            throw new IllegalStateException("cannot other than T or F");
        }
        if (memo[l][r][0] != -1 && memo[l][r][1] != -1) {
            return memo[l][r];
        }
        long trueCount = 0;
        long falseCount = 0;
        for (int p = l; p < r; p += 2) {
            var left = dp(l, p, exp, memo);
            var right = dp(p + 2, r, exp, memo);
            var calculatedCount = calculate(left, right, exp.charAt(p + 1));
            trueCount = (trueCount + calculatedCount[0]) % MOD;
            falseCount = (falseCount + calculatedCount[1]) % MOD;
        }
        return memo[l][r] = new long[]{trueCount, falseCount};
    }

    private static long[] calculate(long[] left, long[] right, char c) {
        return switch (c) {
            case '&' -> {
                long trueCount = left[0] * right[0];
                long falseCount = ((left[0] * right[1] + left[1] * right[0]) % MOD + left[0] * right[0]) % MOD;
                yield new long[]{trueCount, falseCount};
            }
            case '|' -> {
                long trueCount = ((left[0] * right[1] + right[0] * left[1]) % MOD + left[0] * right[0]) % MOD;
                long falseCount = left[1] * right[1];
                yield new long[]{trueCount, falseCount};
            }
            case '^' -> {
                long trueCount = (left[0] * right[1] + left[1] * right[0]) % MOD;
                long falseCount = (left[0] * right[0] + left[1] * right[1]) % MOD;
                yield new long[]{trueCount, falseCount};
            }
            default -> throw new IllegalStateException(c + " is not operation");
        };
    }


    public static void main(String[] args) {
        System.out.println(Solution1.evaluateExp("F&F|F^T|F|T|T"));
    }
}
