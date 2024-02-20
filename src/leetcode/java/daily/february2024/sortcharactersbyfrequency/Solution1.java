package leetcode.java.daily.february2024.sortcharactersbyfrequency;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class Solution1 {
    public String frequencySort(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.merge(c, 1, Integer::sum);
        }
        return freq.entrySet().stream().sorted((a, b) -> b.getValue() - a.getValue()).map(e -> e.getKey().toString().repeat(e.getValue())).collect(Collectors.joining(""));
    }
}
