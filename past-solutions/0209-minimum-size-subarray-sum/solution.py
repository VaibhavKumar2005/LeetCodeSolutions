class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        total = 0
        result = len(nums) + 1

        for i in range(len(nums)):
            total+= nums[i]

            while total >= target:
                result = min(result, i - left + 1)
                total-= nums[left]
                left+=1

        if result == len(nums) + 1:
            return 0
        return result 
