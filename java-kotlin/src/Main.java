import java.io.*;
import java.util.*;

public class Main {

    static class SegmentTree {
        int[] tree;
        int n;

        public SegmentTree(int size) {
            this.n = size;
            this.tree = new int[4 * n];
        }

        public void update(int idx, int addend) {
            update(0, 0, n - 1, idx, addend);
        }

        private void update(int treeIdx, int segLeft, int segRight, int idx, int addend) {
            if (segLeft == segRight) {
                tree[treeIdx] += addend;
                return;
            }
            int mid = (segLeft + segRight) / 2;
            if (idx <= mid) {
                update(2 * treeIdx + 1, segLeft, mid, idx, addend);
            } else {
                update(2 * treeIdx + 2, mid + 1, segRight, idx, addend);
            }
            tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
        }

        public int getKthElement(int k) {
            return getKthElement(0, 0, n - 1, k);
        }

        private int getKthElement(int treeIdx, int segLeft, int segRight, int k) {
            if (k >= tree[treeIdx]) return -1;
            if (segLeft == segRight) return segLeft;

            int leftSum = tree[2 * treeIdx + 1];
            int mid = (segLeft + segRight) / 2;

            if (k < leftSum) {
                return getKthElement(2 * treeIdx + 1, segLeft, mid, k);
            } else {
                return getKthElement(2 * treeIdx + 2, mid + 1, segRight, k - leftSum);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader();
        int n = fr.nextInt();
        int k = fr.nextInt();
        int[] arr = new int[n];
        TreeSet<Integer> uniqueVals = new TreeSet<>();

        for (int i = 0; i < n; i++) {
            arr[i] = fr.nextInt();
            uniqueVals.add(arr[i]);
        }

        List<Integer> sortedUnique = new ArrayList<>(uniqueVals);
        Map<Integer, Integer> valToIdx = new HashMap<>();
        Map<Integer, Integer> idxToVal = new HashMap<>();
        for (int i = 0; i < sortedUnique.size(); i++) {
            valToIdx.put(sortedUnique.get(i), i);
            idxToVal.put(i, sortedUnique.get(i));
        }

        SegmentTree segmentTree = new SegmentTree(sortedUnique.size());
        int left = 0, right = 0;
        List<Integer> res = new ArrayList<>();

        while (right < n) {
            segmentTree.update(valToIdx.get(arr[right]), 1);
            if (right - left + 1 == k) {
                int mid = (k - 1) / 2;
                int medianIdx = segmentTree.getKthElement(mid);
                res.add(idxToVal.get(medianIdx));
                segmentTree.update(valToIdx.get(arr[left]), -1);
                left++;
            }
            right++;
        }

        for (int i = 0; i < res.size(); i++) {
            if (i > 0) System.out.print(" ");
            System.out.print(res.get(i));
        }
        System.out.println();
    }

    // Fast input reader
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}