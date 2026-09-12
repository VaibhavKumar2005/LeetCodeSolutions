class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // next[i] = first interval whose start > a[i].end
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = (lo + hi) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k] = best answer starting from i,
        // when we can still choose k intervals.
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

               
                auto best = dp[i + 1][k];

                auto take = dp[next[i]][k - 1];

                long long newWeight = a[i][2] + take.first;

                vector<int> indices = take.second;
                indices.push_back(a[i][3]);

                sort(indices.begin(), indices.end());

                if (newWeight > best.first ||
                    (newWeight == best.first && indices < best.second)) {

                    best = {newWeight, indices};
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].second;
    }
};
