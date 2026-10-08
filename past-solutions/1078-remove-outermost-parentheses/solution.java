class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder res = new StringBuilder();
        int n = 0;
        for(char c : s.toCharArray()){
            if(c == '('){
                if(n > 0) res.append(c);
                n++;
            }
            else{
                n--;
                if(n > 0) res.append(c);
            }
        }
        return res.toString();
    }
}
