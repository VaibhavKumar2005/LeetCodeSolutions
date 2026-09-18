class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // 1. Find first and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> intervals;

        // 2. Build valid intervals
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;
            int left = first[c];
            int right = last[c];

            bool valid = true;
            for (int i = left; i <= right; i++) {
                int x = s[i] - 'a';

                // This character started before our interval
                if (first[x] < left) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of this character
                right = max(right, last[x]);
            }
            if (valid) {
                intervals.push_back({right, left});
            }
        }

        // 3. Sort by ending position
        sort(intervals.begin(), intervals.end());
        vector<string> ans;
        int previousEnd = -1;

        // 4. Greedily select non-overlapping intervals
        for (auto [right, left] : intervals) {
            if (left > previousEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                previousEnd = right;
            }
        }
        return ans;
    }
};
