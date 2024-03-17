package leetcode.java.graph.cheapestflightswithinkstops;

import leetcode.java.util.Pair;

import java.util.ArrayList;
import java.util.List;

/**
 * DFS solution
 * base case:
 * 1. k < 0 => return Inf
 * 2. curr == dst => return 0
 */
public class Solution1 {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Integer[][] memo = new Integer[n][k + 1];
        List<List<Pair<Integer, Integer>>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] flight : flights) {
            int s = flight[0], d = flight[1], p = flight[2];
            adjList.get(s).add(new Pair<>(d, p));
        }
        var cheapestPrice = dp(src, dst, k, adjList, memo);
        return cheapestPrice == Integer.MAX_VALUE ? -1 : cheapestPrice;
    }

    private int dp(int curr, int dst, int k, List<List<Pair<Integer, Integer>>> adjList, Integer[][] memo) {
        // BASE CASES
        if (curr == dst) {
            return 0;
        }
        if (k < 0) {
            return Integer.MAX_VALUE;
        }
        if (memo[curr][k] != null) {
            return memo[curr][k];
        }
        var possiblePaths = adjList.get(curr);
        int minPrice = Integer.MAX_VALUE;
        for (var pair : possiblePaths) {
            var next = pair.getKey();
            var price = pair.getValue();
            var nextPrice = dp(next, dst, k - 1, adjList, memo);
            if (nextPrice != Integer.MAX_VALUE && nextPrice + price < minPrice) {
                minPrice = nextPrice + price;
            }
        }
        return memo[curr][k] = minPrice;
    }
}
