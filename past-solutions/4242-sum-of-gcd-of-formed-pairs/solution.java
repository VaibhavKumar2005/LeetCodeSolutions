class Solution {
    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] prefixGCD = new int[n]; 
        int mx = 0;

        for (int i = 0; i < n; i++) {
        mx = Math.max(mx, nums[i]);
        prefixGCD[i] = gcd(nums[i], mx);
        }

        Arrays.sort(prefixGCD);

        int left = 0;
        int right = n - 1;
        long ans = 0;

        while(left < right){
            ans += gcd(prefixGCD[left], prefixGCD[right]);
            left++;
            right--;
        }

        return ans;

    }

    private int gcd(int a, int b) {
        while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
        }
        return a;
    }
}
