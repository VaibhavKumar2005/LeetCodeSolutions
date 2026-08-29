class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        // (value, original index)
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        // Sort by value
        sort(arr.begin(), arr.end());
        vector<int> ans(n);

        int i = 0;
        while (i < n) {
            int j = i + 1;
            // Find the current group
            while (j < n &&
                   arr[j].first - arr[j - 1].first <= limit) {
                j++;
            }
            // Get original indices of this group
            vector<int> indices;
            for (int k = i; k < j; k++) {
                indices.push_back(arr[k].second);
            }
            // Smallest index first
            sort(indices.begin(), indices.end());
            // Smallest value goes to smallest index
            for (int k = 0; k < indices.size(); k++) {
                ans[indices[k]] = arr[i + k].first;
            }
            // Move to next group
            i = j;
        }
        return ans;
    }
};

