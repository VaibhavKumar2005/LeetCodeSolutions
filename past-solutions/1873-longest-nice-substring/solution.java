import java.util.*;

class Solution {
    public String longestNiceSubstring(String s) {
        // Base case: a nice string must have at least 2 characters (e.g., 'aA')
        if (s.length() < 2) return "";

        // Use a Set to quickly check if both cases exist
        Set<Character> set = new HashSet<>();
        for (char c : s.toCharArray()) set.add(c);

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            // If the character has both its lowercase and uppercase versions, it's "nice" so far
            if (set.contains(Character.toLowerCase(c)) && set.contains(Character.toUpperCase(c))) {
                continue;
            }

            // If we hit this point, s.charAt(i) is a "break point"
            // The answer must be in either the left part or the right part
            String left = longestNiceSubstring(s.substring(0, i));
            String right = longestNiceSubstring(s.substring(i + 1));
            
            return left.length() >= right.length() ? left : right;
        }

        
        return s;
    }
}
