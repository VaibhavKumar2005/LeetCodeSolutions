class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        vector<int> down(grid[0].size());  
        down[0] = 1;
        for (auto& row : grid) {
            int right = 0;  
            for (int j = 0; j < row.size(); j++) {
                int above = down[j], merged = right + above;  
                merged -= merged >= mod ? mod : 0;  
                down[j] = row[j] ? right : merged;  
                right = row[j] ? above : merged;
            }
        }
        return down.back();
    }
};
