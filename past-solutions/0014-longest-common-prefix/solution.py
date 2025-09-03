from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        first = min(strs)
        last = max(strs)

        for i in range(len(first)):
            if i >= len(last) or first[i] != last[i]:
                return first[:i]
        
        return first

