package algoexpert.famous_algorithms.topological_sort.sol1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// using dfs
public class Program {
  public static List<Integer> topologicalSort(List<Integer> jobs, List<Integer[]> deps) {
    List<List<Integer>> adj = new ArrayList<>();
    for (int i = 0; i <= jobs.size(); i++) {
      adj.add(new ArrayList<>());
    }
    for (Integer[] dep : deps) {
      adj.get(dep[0]).add(dep[1]);
    }
    // System.out.println(adj);
    List<Integer> ans = new ArrayList<>();
    boolean[] visited = new boolean[adj.size()];
    for (int i = 1; i < adj.size(); i++) {
      if (!visited[i]) {
        if (!dfs(i, adj, visited, ans)) {
          return Collections.emptyList();
        }
      }
    }
    // System.out.println(ans);
    Collections.reverse(ans);
    return ans;
  }

  private static boolean dfs(int idx, List<List<Integer>> adj, boolean[] visited, List<Integer> ans) {
    visited[idx] = true;
    for (int neighbour : adj.get(idx)) {
      if (visited[neighbour] || !dfs(neighbour, adj, visited, ans))
        return false;
    }
    ans.add(idx);
    return true;
  }
}
