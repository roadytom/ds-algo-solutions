package leetcode.septemberchallenge2023.extracharactersinastring2707;

import codeforces.java.contest_979.A;

import java.util.*;
import java.util.stream.Collectors;

public class Solution1 {
    public int minExtraChar(String s, String[] dictionary) {
        int[] dp = new int[dictionary.length];
        Arrays.fill(dp, -1);
        return dp(0, s, Arrays.stream(dictionary).collect(Collectors.toSet()), dp);
    }

    public int dp(int index, String str, Set<String> words, int[] dp) {
        if (index == str.length()) {
            return 0;
        } else if (dp[index] != -1) {
            return dp[index];
        }
        int ans = dp(index + 1, str, words, dp) + 1;
        for (int end = index; end < str.length(); end++) {
            String currString = str.substring(index, end + 1);
//            if (words.contains(currString)) {
//                ans = Math.min(ans, dp(end + 1, ))
//            }
        }
        return 0;
    }

    public static void main(String[] args) throws InterruptedException {
//        Solution1 solution1 = new Solution1();
//        System.out.println(solution1.minExtraChar("sayhelloworld",
//                new String[]{
//                        "hello",
//                        "world"
//                }));
        HashMap<Integer, Integer> nums = new HashMap<>();
        nums.put(1, 1);
        nums.put(2, 2);
        nums.put(3, 3);
        nums.put(4, 4);
        nums.put(5, 5);
        var set = nums.keySet();
        var collection = nums.values();
        collection.remove(1);
        System.out.println(nums);
        System.out.println(set);
        ArrayList<Integer> list = new ArrayList<>();
        Collection<Integer> syncCollection = Collections.synchronizedCollection(list);
        Runnable listOperations = () -> {
            list.addAll(Arrays.asList(1, 2, 3, 4, 5, 6));
        };

        Thread thread1 = new Thread(listOperations);
        Thread thread2 = new Thread(listOperations);
        thread1.start();
        thread2.start();
        thread1.join();
        thread2.join();
        System.out.println(list.size());
        System.out.println(syncCollection.size());
    }
}
