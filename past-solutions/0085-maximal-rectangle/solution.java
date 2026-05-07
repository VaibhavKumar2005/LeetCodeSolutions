class Solution {

    public int maximalRectangle(char[][] matrix) {

        int m = matrix.length;
        int n = matrix[0].length;

        int[] h = new int[n];
        int ans = 0;

        for (char[] row : matrix) {

            for (int j = 0; j < n; j++)
                h[j] = row[j] == '1' ? h[j] + 1 : 0;

            ans = Math.max(ans, histogram(h));
        }

        return ans;
    }

    private int histogram(int[] h) {

        ArrayDeque<Integer> st = new ArrayDeque<>();

        int max = 0;

        for (int i = 0; i <= h.length; i++) {

            int curr = (i == h.length) ? 0 : h[i];

            while (!st.isEmpty() && curr < h[st.peek()]) {

                int height = h[st.pop()];

                int left = st.isEmpty() ? -1 : st.peek();

                max = Math.max(max, height * (i - left - 1));
            }

            st.push(i);
        }

        return max;
    }
}
