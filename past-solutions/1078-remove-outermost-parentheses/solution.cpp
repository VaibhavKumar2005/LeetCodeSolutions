class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int n = 0;
        for(char c : s){
            if(c == '('){
                if(n > 0) res += c;
                n++;
            }
            else{
                n--;
                if(n > 0) res += c;
            }
        }
        return res;
    }
};
