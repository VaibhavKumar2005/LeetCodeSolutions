class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        long long res = 0;
        for(int num : nums){
            res = res + (mx - num);
        }
        return res;
    }
};
