class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def remove_substring(s: str, first: str, second: str, points: int):
            stack = []
            score = 0
            for ch in s:
                if stack and stack[-1] == first and ch == second:
                    stack.pop()
                    score += points
                else:
                    stack.append(ch)
            return "".join(stack), score
        
        total_score = 0
        # Decide which substring to remove first
        if x > y:
            # Remove "ab" first
            s, score = remove_substring(s, 'a', 'b', x)
            total_score += score
            s, score = remove_substring(s, 'b', 'a', y)
            total_score += score
        else:
            # Remove "ba" first
            s, score = remove_substring(s, 'b', 'a', y)
            total_score += score
            s, score = remove_substring(s, 'a', 'b', x)
            total_score += score
        
        return total_score

