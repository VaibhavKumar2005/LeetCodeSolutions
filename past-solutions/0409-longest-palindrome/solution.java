class Solution {
    public int longestPalindrome(String s) {
        int[] counts = new int[128];
        
        for (char c : s.toCharArray()) {
            counts[c]++;
        }

        int length = 0;
        boolean hasOdd = false;

        for (int count : counts) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += count - 1; 
                hasOdd = true;       
            }
        }

        return hasOdd ? length + 1 : length;
    }
}
