
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int first = -1;

        // Find first occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    first = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        vector<int> ans;
        if (first == -1)
            return ans;

        // Find last occurrence
        left = first;
        right = nums.size() - 1;
        int last = first;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    last = mid;

                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        for (int i = first; i <= last; i++)
            ans.push_back(i);
        return ans;
    }
};

