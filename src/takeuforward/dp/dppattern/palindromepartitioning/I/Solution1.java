package takeuforward.dp.dppattern.palindromepartitioning.I;

import java.util.ArrayList;
import java.util.List;

public class Solution1 {
    private final List<List<String>> partitions = new ArrayList<>();

    public List<List<String>> partition(String s) {
        Boolean[][] memo = new Boolean[s.length()][s.length()];
        generatePartitions(0, s.length() - 1, s, new ArrayList<>(), memo);
        return partitions;
    }

    private void generatePartitions(int l, int r, String str, List<String> partition, Boolean[][] memo) {
        if (l > r) {
            partitions.add(partition.stream().toList());
        }

        for (int part = l; part <= r; part++) {
            if (isPalindrome(l, part, str, memo)) {
                partition.add(str.substring(l, part + 1));
                generatePartitions(part + 1, r, str, partition, memo);
                partition.removeLast();
            }
        }
    }

    private boolean isPalindrome(int l, int r, String str, Boolean[][] memo) {
        if (memo[l][r] != null) {
            return memo[l][r];
        }
        if (l == r) {
            return memo[l][r] = true;
        }
        boolean equal = str.charAt(l) == str.charAt(r);
        if (l == r - 1) {
            return memo[l][r] = equal;
        }
        return memo[l][r] = equal && memo[l + 1][r - 1];
    }

    /**
     * x, x, x, x, x, x, x, x, x, x, x
     */

    public static void main(String[] args) {
        System.out.println(new Solution1().partition("aab"));
    }
}
