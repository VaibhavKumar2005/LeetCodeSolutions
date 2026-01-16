class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> yes = new HashSet<>();

        for(int n : nums){
            if(yes.contains(n)){
                return true;
            }
            yes.add(n);
        }
        return false;
    }
}
