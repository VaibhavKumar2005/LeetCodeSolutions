class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> str;
        int res = 0;
        for(char c : s){
            if(c == '('){
                str.push(res);
                res = 0;
            }
            else{
                res = str.top() + max(res * 2, 1);
                str.pop();
            }
        }
        return res;
    }
};
