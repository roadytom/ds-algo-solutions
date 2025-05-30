package leetcode.java.daily.february2024.sortcharactersbyfrequency;

import java.util.*;

public class Solution2 {
    public String frequencySort(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.merge(c, 1, Integer::sum);
        }
        List<List<Character>> buckets = new ArrayList<>();
        int maxFrequency = freq.values().stream().max(Comparator.comparingInt(a -> a)).orElseThrow();

        for (int i = 0; i <= maxFrequency; i++) {
            buckets.add(new ArrayList<>());
        }

        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            buckets.get(entry.getValue()).add(entry.getKey());
        }
        StringBuilder builder = new StringBuilder();
        for (int i = maxFrequency; i >= 0; i--) {
            for (char c : buckets.get(i)) {
                builder.append(String.valueOf(c).repeat(i));
            }
        }
        return builder.toString();
    }
}
