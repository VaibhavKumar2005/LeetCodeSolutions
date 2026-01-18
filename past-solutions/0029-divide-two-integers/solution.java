class Solution {
    public int divide(int dividend, int divisor) {
        // Constants for 32-bit integer range
        int INT_MAX = Integer.MAX_VALUE;
        int INT_MIN = Integer.MIN_VALUE;

        // Overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of the result
        boolean negative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive long to avoid overflow
        long a = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);

        int result = 0;

        // Main loop
        while (a >= b) {
            long temp = b;
            int multiple = 1;

            // Find the largest shifted divisor
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
}

