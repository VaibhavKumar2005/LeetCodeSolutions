class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;

        for(int num : nums){
            int count = 0;

            for(int i = 0; i <= nums.size() - k; i++){
                for(int j = i; j < i + k; j++){
                    if(nums[j] == num){
                        count++;

                        break;
                    }
                }
            }
            if(count == 1){
                ans = max(ans, num);
            }
        }
        return ans;
    }
};
