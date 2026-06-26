class Solution {
    class FenwickTree {
        private int[] tree;

        FenwickTree(int n) {
            tree = new int[n + 1];
        }

        void update(int x, int delta) {
            while (x < tree.length) {
                tree[x] += delta;
                x += x & -x;
            }
        }

        int query(int x) {
            int s = 0;
            while (x > 0) {
                s += tree[x];
                x -= x & -x;
            }
            return s;
        }
    }

    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        int offset = n + 1;
        FenwickTree bit = new FenwickTree(2 * n + 5);

        long ans = 0;
        int prefix = 0;

        bit.update(offset, 1);

        for (int x : nums) {
            prefix += (x == target) ? 1 : -1;
            int idx = prefix + offset;
            ans += bit.query(idx - 1);
            bit.update(idx, 1);
        }

        return ans;
    }
}

