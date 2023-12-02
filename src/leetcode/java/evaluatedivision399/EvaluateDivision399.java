package leetcode.java.evaluatedivision399;

import java.util.*;

public class EvaluateDivision399 {
  public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    Map<String, Map<String, Double>> graph = new HashMap<>();
    double[] res = new double[queries.size()];
    for (int i = 0; i < equations.size(); i++) {
      graphAdd(graph, equations.get(i), values[i]);
    }
    for (int i = 0; i < queries.size(); i++) {
      res[i] = bfs(graph,
          queries.get(i).get(0),
          queries.get(i).get(1));
    }
    return res;
  }

  private double bfs(Map<String, Map<String, Double>> graph, String s, String d) {
    Queue<Pair<String, Double>> queue = new ArrayDeque<>();
    Set<String> visited = new HashSet<>();
    queue.offer(new Pair<>(s, 1.0));
    visited.add(s);
    while (!queue.isEmpty()) {
      var curr = queue.poll();
      var map = graph.getOrDefault(curr.first, new HashMap<>());
      if (map.containsKey(d)) {
        return curr.second * map.get(d);
      }
      for (var keyVal : map.entrySet()) {
        if (!visited.contains(keyVal.getKey())) {
          visited.add(keyVal.getKey());
          queue.offer(new Pair<>(keyVal.getKey(),
              curr.second * keyVal.getValue()));
        }
      }
    }
    return -1;
  }

  private void graphAdd(Map<String, Map<String, Double>> graph,
                        List<String> equation, Double value) {
    var oldMap = graph.getOrDefault(equation.get(0), new HashMap<>());
    oldMap.put(equation.get(1), value);
    graph.put(equation.get(0), oldMap);
    oldMap = graph.getOrDefault(equation.get(1), new HashMap<>());
    oldMap.put(equation.get(0), 1. / value);
    graph.put(equation.get(1), oldMap);
  }

  private class Pair<T, T1> {
    T first;

    public Pair(T first, T1 second) {
      this.first = first;
      this.second = second;
    }

    T1 second;

    public Pair() {
    }

  }

  public static void main(String[] args) {
    var ans = new EvaluateDivision399().calcEquation(
        List.of(
            List.of("a", "b"),
            List.of("b", "c")
        ),
        new double[]{2.0, 3.0},
        List.of(
            List.of("a", "c"),
            List.of("b", "a"),
            List.of("a", "e"),
            List.of("a", "a"),
            List.of("x", "x")
        )
    );
    System.out.println(Arrays.toString(ans));
  }
}
