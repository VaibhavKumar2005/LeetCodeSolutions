import java.util.*;

class Solution {

    void solve(String digits, int index, StringBuilder curr, String[] mapping, List<String> ans){

        if(index == digits.length()){
            ans.add(curr.toString());
            return;
        }

        int val = digits.charAt(index) - '0';
        String str = mapping[val];

        for(int i = 0; i < str.length(); i++){
            curr.append(str.charAt(i));
            solve(digits, index + 1, curr, mapping, ans);
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits){

        List<String> ans = new ArrayList<>();

        if(digits.length() == 0)
            return ans;

        String[] mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, 0, new StringBuilder(), mapping, ans);

        return ans;
    }
}
