class Solution {
    public int numberOfSubstrings(String s) {
        int len = s.length();
        int[] lastPos = {-1, -1, -1};
        int total = 0;

        for(int i = 0; i < len; i++){
            lastPos[s.charAt(i) - 'a'] = i;
            total += 1 + Math.min(lastPos[0], Math.min(lastPos[1], lastPos[2])); 
        }
        return total;
    }
}
