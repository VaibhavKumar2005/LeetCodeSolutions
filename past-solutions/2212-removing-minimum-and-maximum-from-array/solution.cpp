class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minimum = 0;
        int maximum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minimum]) {
                minimum = i;
            }

            if (nums[i] > nums[maximum]) {
                maximum = i;
            }
        }

        int left = min(minimum, maximum);
        int right = max(minimum, maximum);

        int fromFront = right + 1;
        int fromBack = n - left;
        int fromBothSides = (left + 1) + (n - right);

        return min({fromFront, fromBack, fromBothSides});
    }
};
