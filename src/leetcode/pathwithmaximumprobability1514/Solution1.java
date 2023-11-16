package leetcode.pathwithmaximumprobability1514;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Solution1 {
    static class Pair {
        private int key;
        private double value;

        public Pair(int key, double value) {
            this.key = key;
            this.value = value;
        }

        public int getKey() {
            return key;
        }

        public void setKey(int key) {
            this.key = key;
        }

        public double getValue() {
            return value;
        }

        public void setValue(double value) {
            this.value = value;
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<List<Pair>> adjList = edgesToAdj(edges, n, succProb);
        double[] maxProb = new double[n];
        boolean[] visited = new boolean[n];

        PriorityQueue<Pair> pq = new PriorityQueue<>((pa, pb) -> Double.compare(pb.getValue(), pa.getValue()));
        pq.offer(new Pair(start, 1D));
        while (!pq.isEmpty()) {
            Pair currNode = pq.poll();
            if (visited[currNode.getKey()]) {
                continue;
            }
            if (currNode.getKey() == end) {
                return currNode.getValue();
            }
            visited[currNode.getKey()] = true;
            relax(currNode, maxProb, pq, adjList);
        }
        return 0;
    }

    private void relax(Pair currNode, double[] maxProb, PriorityQueue<Pair> pq, List<List<Pair>> adjList) {
        int source = currNode.getKey();
        double dist = currNode.getValue();
        for (Pair neigh : adjList.get(source)) {
            int dest = neigh.getKey();
            double destVal = neigh.getValue();
            if (dist * destVal > maxProb[dest]) {
                maxProb[dest] = dist * destVal;
            }
            pq.add(new Pair(dest, maxProb[dest]));
        }
    }


    private List<List<Pair>> edgesToAdj(int[][] edges, int n, double[] succProb) {
        List<List<Pair>> adjList = IntStream.range(0, n).mapToObj(i -> new ArrayList<Pair>()).collect(Collectors.toList());
        for (int i = 0; i < edges.length; i++) {
            int source = edges[i][0];
            int dest = edges[i][1];
            double prob = succProb[i];
            adjList.get(source).add(new Pair(dest, prob));
            adjList.get(dest).add(new Pair(source, prob));
        }
        return adjList;
    }

    public static void main(String[] args) {
        System.out.println(new Solution1().maxProbability(3, new int[][]{{0, 1}, {1, 2}, {0, 2}}, new double[]{0.5, 0.5, 0.2}, 0, 2));
    }
}
