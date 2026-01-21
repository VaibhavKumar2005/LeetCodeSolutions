class Solution {
    public boolean queryString(String s, int n) {
        if (n > 1000) {
            return false;
        }
        for (int currentNumber = n; currentNumber > n / 2; currentNumber--) {
            String binaryRepresentation = Integer.toBinaryString(currentNumber);
            if (!s.contains(binaryRepresentation)) {
                return false;
            }
        }
        return true;
    }
}

