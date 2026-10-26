class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string st;
        for(int i = 0; i < n; i++){
            char curr = s[i];
            if(!st.empty() && st.back() == curr){
                st.pop_back();
            }
            else{
                st.push_back(curr);
            }
        }
        return st;
    }
};
