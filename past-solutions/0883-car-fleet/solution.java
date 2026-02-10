class Solution {
    public int carFleet(int target, int[] position, int[] speed) {

        int n = position.length;

        // Create array of indices
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        // Sort indices by position (descending)
        Arrays.sort(idx, (a, b) -> position[b] - position[a]);

        int fleets = 0;
        double lastTime = 0;

        for (int i : idx) {
            double time = (double)(target - position[i]) / speed[i];

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
}

