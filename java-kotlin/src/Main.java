import java.io.*;
import java.util.*;

public class Main {
    static int n, m, x, y;
    static int[][] array;
    static int[][] count;
    static Integer[][][] memo;  // Null = uncomputed; Return value can also be null if no solution

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        array = new int[n][m];
        count = new int[m][2];

        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                array[i][j] = (row.charAt(j) == '.') ? 0 : 1;
                count[j][array[i][j]]++;
            }
        }

        memo = new Integer[m][y + 2][2];  // prev can go up to y + 1

        Integer res0 = dp(0, 0, 0);
        Integer res1 = dp(0, 0, 1);

        Integer result;
        if (res0 == null && res1 == null) {
            result = null;  // No valid solution at all
        } else if (res0 == null) {
            result = res1;
        } else if (res1 == null) {
            result = res0;
        } else {
            result = Math.min(res0, res1);
        }

        System.out.println(result == null ? "No valid coloring" : result);
    }

    static Integer dp(int colIdx, int prev, int sign) {
        if (colIdx == m) {
            if (prev >= x && prev <= y) return 0;
            return null;
        }

        if (memo[colIdx][prev][sign] != null) return memo[colIdx][prev][sign];

        int opposite = (sign + 1) % 2;
        Integer res = null;

        if (prev == y) {
            Integer next = dp(colIdx + 1, 1, opposite);
            if (next != null) {
                res = next + count[colIdx][opposite];
            }
        } else if (prev < x) {
            Integer next = dp(colIdx + 1, prev + 1, sign);
            if (next != null) {
                res = next + count[colIdx][sign];
            }
        } else {
            Integer stay = dp(colIdx + 1, prev + 1, sign);
            Integer switchColor = dp(colIdx + 1, 1, opposite);

            Integer stayCost = (stay == null) ? null : stay + count[colIdx][sign];
            Integer switchCost = (switchColor == null) ? null : switchColor + count[colIdx][opposite];

            if (stayCost != null && switchCost != null) {
                res = Math.min(stayCost, switchCost);
            } else if (stayCost != null) {
                res = stayCost;
            } else if (switchCost != null) {
                res = switchCost;
            }
        }

        memo[colIdx][prev][sign] = res;
        return res;
    }
}