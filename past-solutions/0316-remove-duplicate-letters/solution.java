class Solution {
    public String removeDuplicateLetters(String s) {
        int[] last = new int[26];
        boolean[] seen = new boolean[26];
        for(int i = 0; i < s.length(); i++){
            last[s.charAt(i) - 'a'] = i;
        }
        Stack<Character> stack = new Stack<>();

        for(int i = 0; i< s.length(); i++){
            char ch = s.charAt(i);
            if (seen[ch - 'a']) continue;

            while(!stack.isEmpty() && ch < stack.peek() && last[stack.peek() - 'a'] > i){
                seen[stack.pop() - 'a'] = false;
            }
            stack.push(ch);
            seen[ch - 'a'] = true;
        }
        StringBuilder result = new StringBuilder();
        for (char c : stack) result.append(c);

        return result.toString();
    }
}
