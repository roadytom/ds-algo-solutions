package leetcode.java.contest.weekly.contest388.shortestuncommonsubstring3076;

import java.util.*;

public class Solution1 {
    public String[] shortestSubstrings(String[] arr) {
        Map<String, Integer> counter = new HashMap<>();
        for (String str : arr) {
            fillCounterWithSubstrings(counter, str);
        }
        String[] ans = new String[arr.length];
        for (int i = 0; i < arr.length; i++) {
            String str = arr[i];
            ans[i] = shortestSubstring(counter, str);
        }
        return ans;
    }

    private void fillCounterWithSubstrings(Map<String, Integer> counter, String str) {
        for (int len = 1; len <= str.length(); len++) {
            Set<String> set = new HashSet<>();
            for (int start = 0; start < str.length() && start + len <= str.length(); start++) {
                String possible = str.substring(start, start + len);
                set.add(possible);
            }
            for (String uniequeString : set) {
                counter.merge(uniequeString, 1, Integer::sum);

            }
        }
    }

    private String shortestSubstring(Map<String, Integer> counter, final String str) {
        for (int len = 1; len <= str.length(); len++) {
            List<String> solutions = new ArrayList<>();
            for (int start = 0; start < str.length() && start + len <= str.length(); start++) {
                String possible = str.substring(start, start + len);
                int count = counter.getOrDefault(possible, 0);
                if (count <= 1) {
                    solutions.add(possible);
                }
            }
            if (!solutions.isEmpty()) {
                return solutions.stream().min(Comparator.naturalOrder()).get();
            }
        }
        return "";
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution1().shortestSubstrings(new String[]{"uj", "q", "wsshb", "fvaj", "maqoi", "rzkw", "vagwc", "vfvjz"})));
    }
}

