class Solution {
    public void moveZeroes(int[] nums) {
      int shift0toright = 0;

      for (int i = 0; i < nums.length; i++){
        if (nums[i]!=0){
            if (i != 0){
                int temp = nums[i];
                nums[i] = nums[shift0toright];
                nums[shift0toright] = temp;
            }
            shift0toright++;
        }
      }  
    }
}
