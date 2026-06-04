class Solution {
    private int waviness(int num) {
        char[] digits = String.valueOf(num).toCharArray();
        if (digits.length < 3) {
            return 0;
        }
        int count = 0;
        for (int i = 1; i < digits.length - 1; i++) {
            char left = digits[i - 1];
            char curr = digits[i];
            char right = digits[i + 1];
            if ((curr > left && curr > right) ||
                (curr < left && curr < right)) {
                count++;
            }
        }
        return count;
    }

    public int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int num = num1; num <= num2; num++) {
            ans += waviness(num);
        }
        return ans;
    }
}
