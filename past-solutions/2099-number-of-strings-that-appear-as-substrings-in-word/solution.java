class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int count = 0;
        for(String pattern : patterns){
            int n = word.length();
            int m = pattern.length();
            boolean found = false;

            for(int i = 0; i <= n - m;i++){
                int j = 0;
                while(j < m && word.charAt(i + j) == pattern.charAt(j)){
                    j++;
                }

                if(j == m){
                    found = true;
                    break;
                }
            }
            if(found){
                count++;
            }
        }

        return count;
    }
}
