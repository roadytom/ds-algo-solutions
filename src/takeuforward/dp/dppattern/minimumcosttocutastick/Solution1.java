package takeuforward.dp.dppattern.minimumcosttocutastick;

import java.util.Arrays;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Solution1 {
    /**
     * [0] 1 3 4 5 [7]
     */
    public int minCost(int n, int[] cuts) {
        int[] newArr = Stream.of(
                IntStream.of(0),
                Arrays.stream(cuts),
                IntStream.of(n)
        ).flatMapToInt(i -> i).toArray();
        Arrays.sort(newArr);
        int len = newArr.length;
        int[][] memo = new int[len][len];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        System.out.println(Arrays.toString(newArr));
        return dp(1, len - 2, newArr, memo);
    }

    private int dp(int i, int j, int[] newArr, int[][] memo) {
        if (i > j) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int minCost = Integer.MAX_VALUE;
        for (int cut = i; cut <= j; cut++) {
            minCost = Math.min(minCost, newArr[j + 1] - newArr[i - 1] + dp(i, cut - 1, newArr, memo) + dp(cut + 1, j, newArr, memo));
        }
        System.out.println(STR."\{i} \{j} -> \{minCost}");
        return memo[i][j] = minCost;
    }

    /**
     * 0 1  2  3   4  5
     * 0 [1, 3, 4, 5] 7
     */
    public static void main(String[] args) {
        System.out.println(new Solution1().minCost(7, new int[]{3, 4, 5, 1}));
    }
}
