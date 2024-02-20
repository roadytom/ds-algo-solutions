package leetcode.java.daily.february2024.perfectsquares;

import java.util.ArrayList;
import java.util.List;

public class Solution1 {
    public int numSquares(int n) {
        Integer[] memo = new Integer[n + 1];
        // in subset [0:i], the least number of squares to target
        List<Integer> squares = new ArrayList<>();
        int s = 1;
        while (s * s <= n) {
            squares.add(s * s);
            s++;
        }
        return dp(n, squares, memo);
    }

    private int dp(int target, List<Integer> squares, Integer[] memo) {
        if (target == 0) {
            return 0;
        }
        if (memo[target] != null) {
            return memo[target];
        }
        int leastNumSq = Integer.MAX_VALUE;
        for (int sq : squares) {
            if (target >= sq) {
                int currNumSq = 1 + dp(target - sq, squares, memo);
                leastNumSq = Math.min(leastNumSq, currNumSq);
            }
        }
        return memo[target] = leastNumSq;
    }
}
