class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d * d <= len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                    if (d != 1 && d * d != len) {
                        divisors[len].push_back(len / d);
                    }
                }
            }
        }
        
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divisors[len]) {
                    int changes = 0;
                    int groupLen = len / d;
                    for (int rem = 0; rem < d; ++rem) {
                        for (int p = 0; p < groupLen / 2; ++p) {
                            int left = i + rem + p * d;
                            int right = i + rem + (groupLen - 1 - p) * d;
                            if (s[left] != s[right]) {
                                ++changes;
                            }
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
    
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) {
                for (int j = 2 * (p - 1); j <= i - 2; ++j) {
                    if (dp[j][p - 1] != INF) {
                        dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};
