class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> one1;
        vector<pair<int, int>> one2;

        int n = img1.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1)
                    one1.push_back({i, j});
                
                if(img2[i][j] == 1)
                    one2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> shift;
        int answer = 0;

        for(auto[i1, j1] : one1){
            for(auto[i2, j2] : one2){
                int rowShift = i2 - i1;
                int columnShift = j2 - j1;
                shift[{rowShift, columnShift}]++;
                answer = max(answer, shift[{rowShift, columnShift}]);
            }
        } 
        return answer;
    }
};
