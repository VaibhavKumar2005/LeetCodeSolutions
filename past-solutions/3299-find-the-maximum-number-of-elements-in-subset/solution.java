class Solution {
    public int maximumLength(int[] nums) {
        Map<Long, Integer> freq = new HashMap<>();

        for (int x : nums)
            freq.put((long) x, freq.getOrDefault((long) x, 0) + 1);

        int ans = 1;

        if (freq.containsKey(1L)) {
            int cnt = freq.get(1L);
            ans = Math.max(ans, cnt % 2 == 0 ? cnt - 1 : cnt);
        }

        for (long x : freq.keySet()) {
            if (x == 1) continue;

            long cur = x;
            int len = 0;

            while (true) {
                Integer cnt = freq.get(cur);

                if (cnt == null)
                    break;

                len++;

                if (cnt == 1)
                    break;

                if (cur > 31622)
                    break;

                cur = cur * cur;
            }

            ans = Math.max(ans, 2 * len - 1);
        }

        return ans;
    }
}
