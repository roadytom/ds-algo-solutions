package leetcode.java.daily.february2024.groupanagrams;

import java.util.ArrayList;
import java.util.List;

/**
 * TIME COMPLEXITY:
 * O(n * n)
 */
public class Solution1 {
    public List<List<String>> groupAnagrams(String[] strs) {
        char[][] frequencies = new char[strs.length][26];
        for (int i = 0; i < strs.length; i++) {
            String str = strs[i];
            for (char c : str.toCharArray()) {
                frequencies[i][c - 'a']++;
            }

        }
        List<List<String>> anagrams = new ArrayList<>();
        boolean[] visited = new boolean[strs.length];
        for (int i = 0; i < strs.length; i++) {
            String curr = strs[i];
            if (visited[i]) {
                continue;
            }
            List<String> group = new ArrayList<>();
            group.add(curr);
            visited[i] = true;

            for (int j = i + 1; j < strs.length; j++) {
                String check = strs[j];
                if (visited[j]) {
                    continue;
                }
                if (isAnagram(frequencies[i], frequencies[j])) {
                    group.add(check);
                    visited[j] = true;
                }
            }
            anagrams.add(group);
        }
        return anagrams;
    }

    private boolean isAnagram(char[] ch1, char[] ch2) {
        for (int i = 0; i < 26; i++) {
            if (ch1[i] != ch2[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}));
    }
}
