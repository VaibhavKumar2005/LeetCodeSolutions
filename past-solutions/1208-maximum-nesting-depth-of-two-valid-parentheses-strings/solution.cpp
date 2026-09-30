class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i){
            if(seq[i] == '('){
                ans[i] = i % 2;
            }
            else{
                ans[i] = (i % 2) ^ 1;
            }
        }
        return ans;
    }
};
