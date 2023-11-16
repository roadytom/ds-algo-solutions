package algoexpert.famous_algorithms.topological_sort.sol2;

import java.sql.Array;
import java.util.*;
import java.util.stream.Collectors;

// using kahn's algorithm
class Program {
    public static List<Integer> topologicalSort(List<Integer> jobs,
                                                List<Integer[]> deps) {
        Map<Integer, Integer> inDegree = jobs.stream()
                .collect(Collectors.toMap(val -> val, val -> 0));
        var adj = getAdjList(deps);
//        System.out.println(adj);
        List<Integer> ans = new ArrayList<>();
        for (Integer[] dep : deps) {
            inDegree.computeIfPresent(dep[1],
                    (k, v) -> v + 1);
        }
//        System.out.println(inDegree);

        Queue<Integer> queue = new ArrayDeque<>();
        for (int job : jobs) {
            if (inDegree.get(job) == 0) {
                queue.offer(job);
            }
        }
        int count = 0;
        while (!queue.isEmpty()) {
            int currNode = queue.poll();
//            System.out.println(currNode);
            ans.add(currNode);
            for (int neighbour : adj.getOrDefault(currNode, Collections.emptyList())) {
                int newVal = inDegree.compute(neighbour,
                        (k, v) -> v - 1);
                if (newVal == 0)
                    queue.offer(neighbour);
            }
            count++;
        }
        if (count != jobs.size())
            return Collections.emptyList();
        else
            return ans;
    }

    private static Map<Integer, List<Integer>> getAdjList(List<Integer[]> deps) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        for (Integer[] dep : deps) {
            adjList.compute(dep[0], (k, v) -> {
                if (v == null)
                    v = new ArrayList<>();
                v.add(dep[1]);
                return v;
            });
        }
        return adjList;
    }

    public static void main(String[] args) {
        System.out.println(Program.topologicalSort(
                List.of(1, 2, 3, 4, 5, 6, 7, 8, 9),
                List.of(
                        new Integer[]{1, 2},
                        new Integer[]{2, 3},
                        new Integer[]{3, 4},
                        new Integer[]{4, 5},
                        new Integer[]{5, 6},
                        new Integer[]{7, 6},
                        new Integer[]{7, 8},
                        new Integer[]{8, 1}
                )
        ));
    }
}

