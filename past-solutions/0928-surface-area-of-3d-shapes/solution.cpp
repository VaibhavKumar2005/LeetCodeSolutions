class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];

                if (h == 0) continue;

                ans += 2 + 4 * h;

                if (i > 0)
                    ans -= 2 * min(h, grid[i - 1][j]);

                if (j > 0)
                    ans -= 2 * min(h, grid[i][j - 1]);
            }
        }

        return ans;
    }
};
