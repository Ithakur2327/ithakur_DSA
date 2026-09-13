class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        sum_ = 0
        n = len(nums)
        prefsum = [0]
        for i in range(n):
            prefsum.append(prefsum[i] + nums[i])
            start = max(0, i-nums[i])
            sum_ += (prefsum[i+1] - prefsum[start])
        return sum_