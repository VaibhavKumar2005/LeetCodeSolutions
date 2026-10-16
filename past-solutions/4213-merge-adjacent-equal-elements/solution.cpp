
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums){
        int n = nums.size();
        vector<long long> st;
        for (int i = 0; i < n; i++) {
            long long curr = nums[i];
            while (!st.empty() && st.back() == curr) {
                st.pop_back();
                curr *= 2;
            }
            st.push_back(curr);
        }
        return st;
    }
};

