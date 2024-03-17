package leetcode.java.takeuforward.dp.climbingstairs;

public class Solution2 {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int oneBefore = 2;
        int twoBefore = 1;
        for (int step = 3; step <= n; step++) {
            int curr = oneBefore + twoBefore;
            twoBefore = oneBefore;
            oneBefore = curr;
        }
        return oneBefore;
    }
}
