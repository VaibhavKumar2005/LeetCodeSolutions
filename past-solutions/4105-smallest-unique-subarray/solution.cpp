class Solution {
private:
    bool hasUnique(const vector<int>& nums, int len) {
        int n = nums.size();
        const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
        const long long base1 = 100003, base2 = 100033;

        long long h1 = 0, h2 = 0;
        long long p1 = 1, p2 = 1;

        for (int i = 0; i < len; i++) {
            h1 = (h1 * base1 + nums[i]) % mod1;
            h2 = (h2 * base2 + nums[i]) % mod2;
            p1 = (p1 * base1) % mod1;
            p2 = (p2 * base2) % mod2;
        }

        vector<long long> hashes;
        hashes.reserve(n - len + 1);
        hashes.push_back((h1 << 32) | h2);

        for (int i = len; i < n; i++) {
            h1 = (h1 * base1 + nums[i] - (nums[i - len] * p1) % mod1 + mod1) % mod1;
            h2 = (h2 * base2 + nums[i] - (nums[i - len] * p2) % mod2 + mod2) % mod2;
            hashes.push_back((h1 << 32) | h2);
        }

        sort(hashes.begin(), hashes.end());
        int m = hashes.size();
        for (int i = 0; i < m; i++) {
            bool leftDiff = (i == 0 || hashes[i] != hashes[i - 1]);
            bool rightDiff = (i == m - 1 || hashes[i] != hashes[i + 1]);
            if (leftDiff && rightDiff) {
                return true;
            }
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n, ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasUnique(nums, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
