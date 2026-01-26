class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int[] map = new int[2 * n + 1];
        
        java.util.Arrays.fill(map, -2); 
        
        map[n] = -1;
        int maxLength = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            count += (nums[i] == 1) ? 1 : -1;
            
            if (map[count + n] >= -1) {
                maxLength = Math.max(maxLength, i - map[count + n]);
            } else {
                map[count + n] = i;
            }
        }
        return maxLength;
    }
}
