import java.util.*;

public class Main {
    static long[] arr;
    static long target;

    static Map<String, Long> memo = new HashMap<>();

    public static long dp(int idx, long curr, long group_idx) {
        String key = idx + "," + curr + "," + group_idx;
        if (memo.containsKey(key)) return memo.get(key);

        if (idx == arr.length) {
            // System.out.println(idx + " " + group_idx + " " + (group_idx == 2 && curr == target ? 1 : 0));
            return 0;
        }
        if (group_idx == 2) {
            return 1;
        }
        long ways = 0;
        ways += dp(idx + 1, curr + arr[idx], group_idx);
        if (curr + arr[idx] == target) {
            ways += dp(idx + 1, 0, group_idx + 1);
        }

        memo.put(key, ways);
        return ways;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = readLong(sc);
        arr = readLongList(sc, n);
        long total_sum = 0;
        for (long x : arr) total_sum += x;
        if (total_sum % 3 != 0) {
            System.out.println("0");
            return;
        }
        target = total_sum / 3;

        System.out.println(dp(0, 0, 0));
    }

    static long readLong(Scanner sc) {
        return sc.nextLong();
    }

    static long[] readLongList(Scanner sc, long n) {
        long[] res = new long[(int)n];
        for (int i = 0; i < n; i++) {
            res[i] = sc.nextLong();
        }
        return res;
    }
}