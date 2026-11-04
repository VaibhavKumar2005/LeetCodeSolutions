class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> low, high;
        long long lowSum = 0, highSum = 0;
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                lowSum -= val;
                high.insert(val);
                highSum += val;
            }
            while (low.size() < high.size()) {
                int val = *high.begin();
                high.erase(high.begin());
                highSum -= val;
                low.insert(val);
                lowSum += val;
            }
        };
        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                lowSum += val;
            } else {
                high.insert(val);
                highSum += val;
            }
            balance();
        };
        auto remove = [&](int val) {
            auto it = low.find(val);
            if (it != low.end()) {
                low.erase(it);
                lowSum -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                highSum -= val;
            }
            balance();
        };
        int m = n - x + 1;
        vector<long long> cost(m);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *low.rbegin();

                cost[i - x + 1] =
                    median * low.size() - lowSum
                    + highSum - median * high.size();
            }
        }
        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);
        for (int t = 1; t <= k; t++) {
            fill(curr.begin(), curr.end(), INF);
            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];
                if (i >= x && prev[i - x] != INF) {
                    long long take =
                        prev[i - x] + cost[i - x];
                    curr[i] = min(curr[i], take);
                }
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};

