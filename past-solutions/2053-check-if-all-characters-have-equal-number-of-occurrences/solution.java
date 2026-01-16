class Solution {
    public boolean areOccurrencesEqual(String s) {
        int[] freq = new int[26];
        
        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i) - 'a']++;
        }

        int expected = 0;
        for(int count : freq){
            if(count!= 0){
                expected = count;
                break;
            }
        }

        for(int count : freq){
            if(count != 0 && expected != count){
                return false;
            }
        }
        return true;
    }
}
