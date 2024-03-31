package takeuforward.dp.dppattern.booleanevaluation;

import static java.lang.StringTemplate.STR;

public class Solution3StriverWay {
    private static final int MOD = 1_000_000_007;

    public static int evaluateExp(String exp) {
        final int n = exp.length();
        long[][][] memo = new long[n][n][2];
        for (long[][] row : memo) {
            for (long[] cell : row) {
                cell[0] = -1;
                cell[1] = -1;
            }
        }
        return (int) dp(0, exp.length() - 1, exp, memo, 1);
    }

    /**
     * returns Key -> true count, Value -> false count
     */
    private static long dp(int l, int r, String exp, long[][][] memo, int flag) {
        // BASE CASE:
        if (l == r) {
            return ((flag == 0 && exp.charAt(l) == 'F') || (flag == 1 && exp.charAt(l) == 'T')) ? 1 : 0;
        }
        if (memo[l][r][flag] != -1) {
            return memo[l][r][flag];
        }
        long count = 0;
        for (int p = l; p < r; p += 2) {
            char operator = exp.charAt(p + 1);
            long leftTrue = dp(l, p, exp, memo, 1);
            long leftFalse = dp(l, p, exp, memo, 0);
            long rightTrue = dp(p + 2, r, exp, memo, 1);
            long rightFalse = dp(p + 2, r, exp, memo, 0);
            switch (operator) {
                case '&' -> {
                    if (flag == 1) {
                        count = modSum(count, leftTrue * rightTrue);
                    } else {
                        count = modSum(count,
                                leftFalse * rightTrue,
                                leftFalse * rightFalse,
                                leftTrue * rightFalse
                        );
                    }
                }
                case '|' -> {
                    if (flag == 1) {
                        count = modSum(
                                count,
                                leftTrue * rightFalse,
                                leftFalse * rightTrue,
                                leftTrue * rightTrue
                        );
                    } else {
                        count = modSum(count, leftFalse * rightFalse);
                    }
                }
                case '^' -> {
                    if (flag == 1) {
                        count = modSum(
                                count,
                                leftTrue * rightFalse,
                                leftFalse * rightTrue
                        );
                    } else {
                        count = modSum(count,
                                leftFalse * rightFalse,
                                leftTrue * rightTrue
                        );
                    }
                }
                default -> throw new IllegalStateException(STR."\{operator} is not operator");
            }
        }
        return memo[l][r][flag] = count;
    }

    private static long modSum(long... additions) {
        long sum = 0;
        for (long addition : additions) {
            sum = (sum + addition) % MOD;
        }
        return sum;
    }


    public static void main(String[] args) {
        System.out.println(Solution1.evaluateExp("T^T|F|T"));
    }
}
