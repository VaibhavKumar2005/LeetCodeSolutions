class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min(need1, need2);
        long long rem1 = need1 - common;
        long long rem2 = need2 - common;

        long long ans = 0;

        ans += common * min(costBoth, cost1 + cost2);
        ans += rem1 * min(costBoth, cost1);
        ans += rem2 * min(costBoth, cost2); 

        return ans;
    }
};
