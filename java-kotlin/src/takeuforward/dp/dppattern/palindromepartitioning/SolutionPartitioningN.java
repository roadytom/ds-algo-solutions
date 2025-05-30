package takeuforward.dp.dppattern.palindromepartitioning;

import java.util.ArrayList;
import java.util.List;

public class SolutionPartitioningN {
    private final List<List<Integer>> ways = new ArrayList<>();

    private void generateWay(int n, int lastOperand, List<Integer> way) {
        if (n == 0) {
            ways.add(new ArrayList<>(way));
        }
        if (lastOperand > n) {
            return;
        }
        for (int operand = lastOperand; operand <= n; operand++) {
            way.addLast(operand);
            generateWay(n - operand, operand, way);
            way.removeLast();
        }
    }

    int countWays(int n) {
        List<Integer> way = new ArrayList<>();
        generateWay(n, 1, way);
        System.out.println(ways);
        return ways.size();
    }

    public static void main(String[] args) {
        System.out.println(new SolutionPartitioningN().countWays(5));
    }
}
