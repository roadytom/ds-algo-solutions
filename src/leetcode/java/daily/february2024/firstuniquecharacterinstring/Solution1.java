package leetcode.java.daily.february2024.firstuniquecharacterinstring;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
    public int firstUniqChar(String s) {
        Map<Character, Integer> store = new HashMap<>();
        for (char c : s.toCharArray()) {
            store.merge(c, 1, Integer::sum);
        }
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (store.get(c) == 1) {
                return i;
            }
        }
        return -1;
    }
}
