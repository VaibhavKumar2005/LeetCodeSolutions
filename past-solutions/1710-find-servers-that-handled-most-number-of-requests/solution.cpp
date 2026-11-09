class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Stores available server IDs in sorted order
        set<int> available;

        // Stores {completion time, server ID}
        // Earliest finishing request comes first
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // Initialize all servers as available
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Count requests handled by each server
        vector<int> count(k, 0);

        int maxRequests = 0;

        // Process requests in arrival order
        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests have finished
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                available.insert(server);
                busy.pop();
            }

            // All servers are busy, drop this request
            if (available.empty()) {
                continue;
            }

            // Preferred server for this request
            int preferred = i % k;

            // Find the next available server
            auto it = available.lower_bound(preferred);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Mark this server as busy
            available.erase(it);

            // Update its request count
            count[server]++;

            maxRequests = max(maxRequests, count[server]);

            // Calculate when this server becomes available again
            long long finishTime =
                (long long)arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        // Collect all busiest servers
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

