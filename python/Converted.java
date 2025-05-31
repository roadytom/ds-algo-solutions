import java.io.*;
import java.util.*;

public class Main {

    static final int MOD = 1000000007;
    static final int INF = Integer.MAX_VALUE;

    static int[] readIntList(BufferedReader br) throws IOException {
        String[] parts = br.readLine().split(" ");
        int[] result = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    static int readInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    static class BinaryLiftingTree {
        int nodesCount;
        int maxLog;
        int[][] up;
        int[][] upMin;
        int[] depth;
        List<List<int[]>> tree;
        boolean built = false;

        public BinaryLiftingTree(int nodesCount) {
            this.nodesCount = nodesCount;
            this.maxLog = (int) (Math.log(nodesCount) / Math.log(2)) + 1;
            this.up = new int[nodesCount][maxLog];
            this.upMin = new int[nodesCount][maxLog];
            this.depth = new int[nodesCount];
            this.tree = new ArrayList<>();
            for (int i = 0; i < nodesCount; i++) {
                tree.add(new ArrayList<>());
                Arrays.fill(up[i], -1);
                Arrays.fill(upMin[i], -1);
            }
        }

        public void addEdge(int a, int b, int weight) {
            tree.get(a).add(new int[]{b, weight});
            tree.get(b).add(new int[]{a, weight});
            built = false;
        }

        public void build(int root, boolean recursive) {
            if (recursive) {
                dfs(root, -1);
            } else {
                dfsIterative(root);
            }
            built = true;
        }

        private void checkBuilt() {
            if (!built) {
                throw new IllegalStateException("Tree not built. Call build() before calling.");
            }
        }

        void dfs(int node, int parent) {
            for (int[] pair : tree.get(node)) {
                int child = pair[0], weight = pair[1];
                if (child == parent) continue;
                depth[child] = depth[node] + 1;
                up[child][0] = node;
                upMin[child][0] = weight;
                for (int log = 1; log < maxLog; log++) {
                    if (up[child][log - 1] != -1) {
                        up[child][log] = up[up[child][log - 1]][log - 1];
                        upMin[child][log] = Math.min(upMin[child][log - 1], upMin[up[child][log - 1]][log - 1]);
                    }
                }
                dfs(child, node);
            }
        }

        void dfsIterative(int root) {
            Deque<int[]> stack = new ArrayDeque<>();
            stack.push(new int[]{root, -1});
            while (!stack.isEmpty()) {
                int[] current = stack.pop();
                int node = current[0], parent = current[1];
                for (int[] pair : tree.get(node)) {
                    int child = pair[0], weight = pair[1];
                    if (child == parent) continue;
                    depth[child] = depth[node] + 1;
                    up[child][0] = node;
                    upMin[child][0] = weight;
                    for (int log = 1; log < maxLog; log++) {
                        if (up[child][log - 1] != -1) {
                            up[child][log] = up[up[child][log - 1]][log - 1];
                            upMin[child][log] = Math.min(upMin[child][log - 1], upMin[up[child][log - 1]][log - 1]);
                        }
                    }
                    stack.push(new int[]{child, node});
                }
            }
        }

        public int getKthAncestor(int node, int k) {
            checkBuilt();
            for (int i = 0; i < maxLog; i++) {
                if ((k & (1 << i)) != 0) {
                    node = up[node][i];
                    if (node == -1) break;
                }
            }
            return node;
        }

        public int getKthMinAncestor(int node, int k) {
            checkBuilt();
            int minAncestor = INF;
            for (int i = 0; i < maxLog; i++) {
                if ((k & (1 << i)) != 0) {
                    minAncestor = Math.min(minAncestor, upMin[node][i]);
                    node = up[node][i];
                    if (node == -1) break;
                }
            }
            return minAncestor;
        }

        public int getLCA(int a, int b) {
            checkBuilt();
            if (depth[a] > depth[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            int diff = depth[b] - depth[a];
            b = getKthAncestor(b, diff);
            if (a == b) return a;
            for (int log = maxLog - 1; log >= 0; log--) {
                if (up[a][log] != -1 && up[a][log] != up[b][log]) {
                    a = up[a][log];
                    b = up[b][log];
                }
            }
            return up[a][0];
        }

        public int getDistance(int a, int b) {
            checkBuilt();
            int lca = getLCA(a, b);
            return depth[a] + depth[b] - 2 * depth[lca];
        }

        public int getMinInPath(int a, int b) {
            checkBuilt();
            int lca = getLCA(a, b);
            return Math.min(
                getKthMinAncestor(a, depth[a] - depth[lca]),
                getKthMinAncestor(b, depth[b] - depth[lca])
            );
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] counts = readIntList(br);
        int nodesCount = counts[0];
        int edgesCount = counts[1];
        BinaryLiftingTree blt = new BinaryLiftingTree(nodesCount);
        for (int i = 0; i < edgesCount; i++) {
            int[] edge = readIntList(br);
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            int weight = edge[2];
            blt.addEdge(a, b, weight);
        }
        blt.build(0, false);
        int queryCount = readInt(br);
        for (int i = 0; i < queryCount; i++) {
            int[] query = readIntList(br);
            int a = query[0] - 1;
            int b = query[1] - 1;
            System.out.println(blt.getMinInPath(a, b));
        }
    }
}