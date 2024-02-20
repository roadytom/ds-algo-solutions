package leetcode.java.dp.minimummovestospreadstonesovergrid;

import java.util.ArrayList;
import java.util.List;

public class Solution1 {
    static class Point {
        int x;
        int y;
        int val;

        public boolean isGiver() {
            return val > 1;
        }

        public boolean isReceiver() {
            return val == 0;
        }

        public Point(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }

    public int minimumMoves(int[][] grid) {
        List<Point> givers = new ArrayList<>();
        List<Point> receivers = new ArrayList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                Point point = new Point(i, j, grid[i][j]);
                if (point.isGiver()) {
                    givers.add(point);
                } else if (point.isReceiver()) {
                    receivers.add(point);
                }
            }
        }
        return minimumMoves(givers, receivers, 0);
    }

    private int minimumMoves(List<Point> givers, List<Point> receivers, int receiverIndex) {
        if (receiverIndex >= receivers.size()) {
            return 0;
        }
        int min = Integer.MAX_VALUE;
        for (Point point : givers) {
            if (point.val == 1) continue;
            point.val--;
            min = Math.min(min, minimumMoves(givers, receivers, receiverIndex + 1) + manhattanDistance(point, receivers.get(receiverIndex)));
            point.val++;
        }
        return min;
    }

    private int manhattanDistance(Point p, Point r) {
        return Math.abs(p.x - r.x) + Math.abs(p.y - r.y);
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().minimumMoves(new int[][]{{3, 2, 0}, {0, 1, 0}, {0, 3, 0}}));
    }
}
