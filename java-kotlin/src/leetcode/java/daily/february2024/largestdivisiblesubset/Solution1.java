package leetcode.java.daily.february2024.largestdivisiblesubset;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution1 {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums.length == 0) {
            return Collections.emptyList();
        }
        Arrays.sort(nums);
        List<List<Integer>> memo = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            memo.add(null);
        }
        List<Integer> maxList = Collections.emptyList();
        for (int i = 0; i < nums.length; i++) {
            List<Integer> currMaxList = dp(i, nums, memo);
            if (maxList.size() < currMaxList.size()) {
                maxList = currMaxList;
            }
        }
        return maxList;
    }

    private List<Integer> dp(int index, int[] nums, List<List<Integer>> memo) {
        if (memo.get(index) != null) {
            return memo.get(index);
        }
        List<Integer> maxSubsetList = Collections.emptyList();
        for (int i = 0; i < index; i++) {
            if (nums[index] % nums[i] == 0) {
                List<Integer> prevSubsetList = dp(i, nums, memo);
                if (maxSubsetList.size() < prevSubsetList.size()) {
                    maxSubsetList = prevSubsetList;
                }
            }
        }
        List<Integer> currMaxSubsetList = new ArrayList<>(maxSubsetList);
        currMaxSubsetList.add(nums[index]);
        memo.set(index, currMaxSubsetList);
        return currMaxSubsetList;
    }
}
