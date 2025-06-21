import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1_000_000_007;
    static final double INF = Double.POSITIVE_INFINITY;

    static int[] readIntArray(BufferedReader br) throws IOException {
        return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    TreeMap<Integer, Integer> low = new TreeMap<>();
    TreeMap<Integer, Integer> up = new TreeMap<>();
    long sumLow = 0;
    long sumUp = 0;
    long lowCount = 0;
    long upCount = 0;
    int k;

    void insert(int val) {
        if (low.isEmpty() || low.lastKey() >= val) {
            incCount(low, val);
            sumLow += val;
            lowCount += 1;
        } else {
            incCount(up, val);
            sumUp += val;
            upCount += 1;
        }
        balance();
    }

    void pop(int val) {
        if (low.isEmpty()) throw new RuntimeException("empty");

        if (low.containsKey(val) && low.lastKey() >= val) {
            sumLow -= val;
            lowCount -= 1;
            decCountOrRemove(low, val);
        } else {
            sumUp -= val;
            upCount -= 1;
            decCountOrRemove(up, val);
        }
        balance();
    }

    void decCountOrRemove(Map<Integer, Integer> map, Integer key) {
        map.merge(key, -1, (oldVal, newVal) -> (oldVal + newVal == 0) ? null : oldVal + newVal);
    }

    void incCount(Map<Integer, Integer> map, Integer key) {
        map.merge(key, 1, Integer::sum);
    }

    void balance() {
        while (lowCount - upCount > 1) {
            var removeVal = low.lastKey();
            decCountOrRemove(low, removeVal);
            sumLow -= removeVal;
            sumUp += removeVal;
            lowCount -= 1;
            incCount(up, removeVal);
            upCount += 1;
        }
        while (upCount > lowCount) {
            int removeVal = up.firstKey();
            decCountOrRemove(up, removeVal);
            sumUp -= removeVal;
            sumLow += removeVal;
            upCount -= 1;
            incCount(low, removeVal);
            lowCount += 1;
        }
    }

    void run() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int[] nk = readIntArray(br);
        int n = nk[0];
        k = nk[1];
        int[] arr = readIntArray(br);

        int left = 0, right = 0;
        List<Long> ans = new ArrayList<>();

        while (right < arr.length) {
            insert(arr[right]);
            if (right - left + 1 == k) {
                int med = low.lastKey();
                long cost = sumUp - (long) med * upCount + (long) med * lowCount - sumLow;
                ans.add(cost);
                pop(arr[left]);
                left++;
            }
            right++;
        }

        for (int i = 0; i < ans.size(); i++) {
            out.append(ans.get(i));
            if (i < ans.size() - 1) out.append(" ");
        }
        System.out.println(out);
    }
}