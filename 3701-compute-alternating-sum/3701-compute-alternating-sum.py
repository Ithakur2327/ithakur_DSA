class Solution:
    def alternatingSum(self, nums: List[int]) -> int:
         count = 0
         for i in range(len(nums)):
            if i%2 == 0:
                count += nums[i]
            else:
                count -= nums[i]

         return count