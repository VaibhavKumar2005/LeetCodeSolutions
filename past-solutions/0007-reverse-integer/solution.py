class Solution:
    def reverse(self, x: int) -> int:
        rev = 0

        sign = -1 if x < 0 else 1
        
        num = x if x > 0 else -x
        

        while num!= 0:
            rev = rev * 10 + num % 10
            num //= 10

        if x < 0:
            rev = -rev

        if rev < -2**31 or rev > 2**31 - 1:
            return 0

        return rev
