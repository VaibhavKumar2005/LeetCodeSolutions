class Solution {
public:

    int GCD(int a, int b){
        while(b != 0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mx)
                mx = nums[i];
            if (nums[i] < mn)
                mn = nums[i];
        }
        return GCD(mx, mn);
    
    }
};
