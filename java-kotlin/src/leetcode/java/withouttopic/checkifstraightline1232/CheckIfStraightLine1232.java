package leetcode.java.withouttopic.checkifstraightline1232;

public class CheckIfStraightLine1232 {
    public boolean checkStraightLine(int[][] cs) {
        double x1 = cs[0][0], y1 = cs[0][1];
        double x2 = cs[1][0], y2 = cs[1][1];
        for (int i = 3; i < cs.length; i++) {
            double x3 = cs[i][0], y3 = cs[i][1];
            double res = (y1 - y2) * (x3 - x1) / (x1 - x2);
            System.out.println(res);
            if (y3 - y1 != (y1 - y2) * (x3 - x1) / (x1 - x2)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new CheckIfStraightLine1232().checkStraightLine(new int[][]{{1, 2}, {2, 3}, {3, 5}}));
    }
}
