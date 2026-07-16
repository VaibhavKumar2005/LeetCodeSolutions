class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD;
        int mx = 0;

        //Construct prefixGCD

        for(int x : nums){
            mx = max(mx, x);
            prefixGCD.push_back(gcd(x, mx));
        }

        //Sort Arrays
        sort(prefixGCD.begin(), prefixGCD.end());

        //Pair Largest and Smallest Numbers

        int left = 0, right = n - 1;
        long long ans = 0;

        while(left < right){
            ans += gcd(prefixGCD[left], prefixGCD[right]);
            left++;
            right--;
        }

        return ans;
    }
};
