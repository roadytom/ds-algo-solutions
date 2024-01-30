package leetcode.java.daily.january2024.outofboundarypaths;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
  private record Triple(int first, int second, int third) {
  }

  int[][] directions = new int[][]{
      {0, 1},
      {1, 0},
      {0, -1},
      {-1, 0},
  };
  private final int MOD = 1_000_000_007;

  public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    Map<Triple, Integer> memo = new HashMap<>();
    return findPaths(m, n, maxMove, startRow, startColumn, memo);
  }

  private int findPaths(int m, int n, int movesLeft, int r, int c, Map<Triple, Integer> memo) {
    if (r == m || c == n || r < 0 || c < 0) {
      return 1;
    }
    if (movesLeft == 0) {
      return 0;
    }
    Triple currKey = new Triple(r, c, movesLeft);
    if (memo.containsKey(currKey)) {
      return memo.get(currKey);
    }
    int pathSum = 0;
    for (int[] direction : directions) {
      int newR = r + direction[0];
      int newC = c + direction[1];
      pathSum = add(pathSum, findPaths(m, n, movesLeft - 1, newR, newC, memo));
    }
    memo.put(currKey, pathSum);
    return pathSum;
  }

  private int add(int a, int b) {
    return (a + b) % MOD;
  }
}
