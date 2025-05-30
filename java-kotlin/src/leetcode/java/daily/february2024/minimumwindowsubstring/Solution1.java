package leetcode.java.daily.february2024.minimumwindowsubstring;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {
    public String minWindow(String s, String t) {
        int low = 0, high = 0;
        Map<Character, Integer> frequencyT = new HashMap<>();
        for (char c : t.toCharArray()) {
            frequencyT.merge(c, 1, Integer::sum);
        }
        // size, left, right
        int[] ans = {-1, 0, 0};
        int have = 0, need = frequencyT.size();
        Map<Character, Integer> frequencyS = new HashMap<>();
        while (high < s.length()) {
            var c = s.charAt(high);
            var newFrequency = frequencyS.merge(c, 1, Integer::sum);
            if (newFrequency.equals(frequencyT.get(c))) {
                have++;
            }
            // check the contract, and try to shrink windows
            while (have == need) {
                updateAnsWithMinSize(ans, low, high);
                var toBeRemovedChar = s.charAt(low);
                frequencyS.computeIfPresent(toBeRemovedChar, (key, oldVal) -> oldVal - 1);
                if (frequencyT.containsKey(toBeRemovedChar) && frequencyS.get(toBeRemovedChar) < frequencyT.get(toBeRemovedChar)) {
                    have--;
                }
                low++;
            }
            high++;
        }
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }

    private void updateAnsWithMinSize(int[] ans, int low, int high) {
        if (ans[0] == -1 || ans[0] > high - low + 1) {
            ans[0] = high - low + 1;
            ans[1] = low;
            ans[2] = high;
        }
    }
}
