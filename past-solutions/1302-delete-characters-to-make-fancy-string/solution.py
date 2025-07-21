class Solution:
    def makeFancyString(self, s: str) -> str:
        res = []
        count = 1  # count of current repeating character

        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                count += 1
            else:
                count = 1  # reset count when char changes

            if count < 3:
                res.append(s[i])
            # if count >= 3, skip adding

        # Add the first character (we skipped it above)
        return s[0] + ''.join(res)

