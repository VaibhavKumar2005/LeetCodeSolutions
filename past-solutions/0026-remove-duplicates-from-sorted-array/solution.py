class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        i = 1 # Pointer for the position to insert unique elements
        for j in range(1, len(nums)):
            if nums [j] != nums [j - 1]:
                nums[i] = nums[j]
                i += 1

        return i         
