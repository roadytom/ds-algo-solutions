package algoexpert.veryhard.nonattackingqueens.sol1;

import java.util.Set;

public class Program {
    public int nonAttackingQueens(int n) {
        for (int i = 0; i < n; i++) {

        }
        return -1;
    }

    private boolean isAttacks(Set<Point> queens, Point newPoint) {
        for (Point existingPoints : queens) {
            if (existingPoints.x == newPoint.x
                    || existingPoints.y == newPoint.y
                    || Math.abs(existingPoints.x - newPoint.x) == Math.abs(existingPoints.y - newPoint.y)) {
                return true;
            }
        }
        return false;
    }

//    private boolean possible(Set<Point>)


    private record Point(int x, int y) {
    }


}
