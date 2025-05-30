package leetcode.java.daily.february2024.groupanagrams;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Categorize each string with frequencies
 * O(n * k) time complexity
 */
public class Solution2 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<List<Integer>, List<String>> store = new HashMap<>();
        for (String str : strs) {
            List<Integer> key = new ArrayList<>();
            for (int i = 0; i < 26; i++) {
                key.add(0);
            }
            for (char c : str.toCharArray()) {
                key.set(c - 'a', key.get(c - 'a') + 1);
            }
            List<String> strings = store.getOrDefault(key, new ArrayList<>());
            strings.add(str);
            store.put(key, strings);
        }
        return new ArrayList<>(store.values());
    }
}
