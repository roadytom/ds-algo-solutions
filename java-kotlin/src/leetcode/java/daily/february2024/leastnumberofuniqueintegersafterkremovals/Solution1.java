package leetcode.java.daily.february2024.leastnumberofuniqueintegersafterkremovals;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Solution1 {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : arr) {
            freq.merge(num, 1, Integer::sum);
        }
        var list = freq.entrySet().stream().sorted(Comparator.comparingInt(Map.Entry::getValue))
                .toList();
        int removed = 0;
        for (var integerIntegerEntry : list) {
            if (k < integerIntegerEntry.getValue()) {
                break;
            }
            k -= integerIntegerEntry.getValue();
            removed++;
        }
        return list.size() - removed;
    }
}
