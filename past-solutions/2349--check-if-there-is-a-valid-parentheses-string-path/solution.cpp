class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 == 1)
            return false;

        // A valid parentheses string must start with '('
        if (grid[0][0] == ')')
            return false;

        // A valid parentheses string must end with ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(m + n, false)
            )
        );

        // Starting cell
        dp[0][0][1] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                for (int balance = 0; balance <= m + n; balance++) {
                    // We can come from TOP
                    if (i > 0 && dp[i - 1][j][balance]) {
                        if (grid[i][j] == '(') {
                            dp[i][j][balance + 1] = true;
                        }
                        else if (balance > 0) {
                            dp[i][j][balance - 1] = true;
                        }
                    }
                    // We can come from LEFT
                    if (j > 0 && dp[i][j - 1][balance]) {

                        if (grid[i][j] == '(') {
                            dp[i][j][balance + 1] = true;
                        }
                        else if (balance > 0) {
                            dp[i][j][balance - 1] = true;
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
