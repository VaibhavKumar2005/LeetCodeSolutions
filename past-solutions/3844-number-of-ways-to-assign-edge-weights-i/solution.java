class Solution {

    private static final long MOD = 1_000_000_007L;
    private int maxDepth = 0;

    public int assignEdgeWeights(int[][] edges) {

        int n = edges.length + 1;

        List<Integer>[] graph = new ArrayList[n + 1];

        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].add(v);
            graph[v].add(u);
        }

        dfs(1, 0, 0, graph);

        return (int) modPow(2, maxDepth - 1);
    }

    private void dfs(int node, int parent, int depth,
                     List<Integer>[] graph) {

        maxDepth = Math.max(maxDepth, depth);

        for (int neighbor : graph[node]) {

            if (neighbor == parent) {
                continue;
            }

            dfs(neighbor, node, depth + 1, graph);
        }
    }

    private long modPow(long base, long exp) {

        long result = 1;

        while (exp > 0) {

            if ((exp & 1) == 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }
}
