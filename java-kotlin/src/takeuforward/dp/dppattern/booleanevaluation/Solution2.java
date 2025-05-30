package takeuforward.dp.dppattern.booleanevaluation;

public class Solution2 {
    private static final int MOD = 1_000_000_007;

    public static int evaluateExp(String exp) {
        final int n = exp.length();
        long[][][] dp = new long[n + 1][n + 1][2];
        for (int i = 0; i < n; i+=2) {
            if (exp.charAt(i) == 'T') {
                dp[i][i] = new long[]{0, 1};
            } else {
                dp[i][i] = new long[]{1, 0};
            }
        }
        for (int i = n - 1; i >= 0; i-=2) {
            for (int j = i + 2; j < n; j+=2) {
                long trueCount = 0;
                long falseCount = 0;
                for (int p = i; p < j; p += 2) {
                    var left = dp[i][p];
                    var right = dp[p + 2][j];
                    var calculatedCount = calculate(left, right, exp.charAt(p + 1));
                    trueCount = (trueCount + calculatedCount[1]) % MOD;
                    falseCount = (falseCount + calculatedCount[0]) % MOD;
                }
                dp[i][j] = new long[]{falseCount, trueCount};
            }
        }
        return (int) dp[0][n - 1][1];
    }

    private static long[] calculate(long[] left, long[] right, char c) {
        return switch (c) {
            case '&' -> {
                long trueCount = left[1] * right[1];
                long falseCount = ((left[1] * right[0] + left[0] * right[1]) % MOD + left[0] * right[0]) % MOD;
                yield new long[]{falseCount, trueCount};
            }
            case '|' -> {
                long trueCount = ((left[1] * right[0] + right[1] * left[0]) % MOD + left[1] * right[1]) % MOD;
                long falseCount = left[0] * right[0];
                yield new long[]{falseCount, trueCount,};
            }
            case '^' -> {
                long trueCount = (left[1] * right[0] + left[0] * right[1]) % MOD;
                long falseCount = (left[1] * right[1] + left[0] * right[0]) % MOD;
                yield new long[]{falseCount, trueCount};
            }
            default -> throw new IllegalStateException(c + " is not operation");
        };
    }

    public static void main(String[] args) {
        System.out.println(Solution2.evaluateExp("F|T^F"));
    }
}
