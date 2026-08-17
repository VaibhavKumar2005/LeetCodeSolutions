class Solution {
    vector<vector<int>> dp;

    int solve(vector<int>& stones, int l, int r) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int total = 0;
        for (int i = l; i <= r; i++)
            total += stones[i];

        int leftSum = 0;
        int ans = 0;

        for (int i = l; i < r; i++) {
            leftSum += stones[i];
            int rightSum = total - leftSum;

            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(stones, l, i));
            }
            else if (leftSum > rightSum) {
                ans = max(ans, rightSum + solve(stones, i + 1, r));
            }
            else {
                ans = max(ans,
                          leftSum + max(solve(stones, l, i),
                                        solve(stones, i + 1, r)));
            }
        }

        return dp[l][r] = ans;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(stoneValue, 0, n - 1);
    }
};
