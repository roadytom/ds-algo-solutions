package leetcode.maxdistance1162;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class MaxDistance1162 {
  public static void main(String[] args) {
    System.out.println(new MaxDistance1162().maxDistance(
        new int[][]{
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }
    ));
  }

  public int maxDistance(int[][] grid) {
    int max = -1;
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid.length; j++) {
        if (grid[i][j] == 0) {
          max = Math.max(solve(i, j, grid), max);
          int a = max;
        }
      }
    }
    return max;
  }

  private int[][] possibleWays(int x, int y, int[][] grid, boolean[][] visited) {
    List<int[]> ans = new ArrayList<>();
    int[][] directions = new int[][]{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };
    for (int[] direction : directions) {
      int newX = x + direction[0];
      int newY = y + direction[1];
      if (newX < grid.length && newX >= 0 && newY < grid[0].length && newY >= 0 && !visited[newX][newY]) {
        ans.add(new int[]{
            newX, newY
        });
      }
    }
    int[][] ansArr = new int[ans.size()][2];
    int index = 0;
    for (int[] dr : ans) {
      ansArr[index++] = dr;
    }
    return ansArr;
  }

  public int solve(int x, int y, int[][] grid) {
    final int R = grid.length;
    final int C = grid.length;
    Queue<int[]> q = new ArrayDeque<>();
    q.offer(new int[]{x, y, 0});
    int dist = 1;
    boolean[][] visited = new boolean[R][C];
    visited[x][y] = true;
    while (!q.isEmpty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int[] curr = q.poll();
        for (int[] pos : possibleWays(curr[0], curr[1], grid, visited)) {
          System.out.println(pos[0] + " " + pos[1]);
          if (grid[pos[0]][pos[1]] == 1) {
            return dist;
          } else {
            visited[pos[0]][pos[1]] = true;
            q.offer(pos);
          }
        }
      }
      dist++;
    }
    return -1;
  }
}