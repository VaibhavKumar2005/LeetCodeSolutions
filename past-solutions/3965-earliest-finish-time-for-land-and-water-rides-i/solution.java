class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {

        int n = landStartTime.length;
        int m = waterStartTime.length;

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                int finish1 = Math.max(
                        waterStartTime[j],
                        landStartTime[i] + landDuration[i]
                ) + waterDuration[j];

                // Water -> Land
                int finish2 = Math.max(
                        landStartTime[i],
                        waterStartTime[j] + waterDuration[j]
                ) + landDuration[i];

                ans = Math.min(ans, Math.min(finish1, finish2));
            }
        }

        return ans;
    }
}
