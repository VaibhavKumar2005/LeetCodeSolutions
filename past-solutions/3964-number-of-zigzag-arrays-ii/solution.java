class Solution {

    private static final long MOD = 1_000_000_007L;

    private long[][] multiply(long[][] A, long[][] B) {
        int n = A.length;
        long[][] C = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    private long[][] power(long[][] base, long exp) {
        int n = base.length;

        long[][] res = new long[n][n];

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int states = 2 * m;

        long[][] T = new long[states][states];

        for (int x = 0; x < m; x++) {

            for (int y = 0; y < x; y++) {
                T[y + m][x] = 1;
            }

            for (int y = x + 1; y < m; y++) {
                T[y][x + m] = 1;
            }
        }

        long[][] P = power(T, n - 1);

        long[] up = new long[states];
        long[] down = new long[states];

        for (int x = 0; x < m; x++) {
            up[x] = 1;
            down[x + m] = 1;
        }

        long ans = 0;

        for (int i = 0; i < states; i++) {
            long cur = 0;

            for (int j = 0; j < states; j++) {
                cur = (cur + P[i][j] * up[j]) % MOD;
            }

            ans = (ans + cur) % MOD;
        }

        for (int i = 0; i < states; i++) {
            long cur = 0;

            for (int j = 0; j < states; j++) {
                cur = (cur + P[i][j] * down[j]) % MOD;
            }

            ans = (ans + cur) % MOD;
        }

        return (int) ans;
    }
}
