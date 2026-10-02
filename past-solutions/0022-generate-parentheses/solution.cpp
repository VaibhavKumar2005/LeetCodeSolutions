class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                const vector<string>& left_combinations = dp[j];
                const vector<string>& right_combinations = dp[i - 1 - j];
                
                for (const string& left : left_combinations) {
                    for (const string& right : right_combinations) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return dp[n];
    }
};

