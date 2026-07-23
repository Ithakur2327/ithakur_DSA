class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)

        if n<=2:
            return n

        m=0
        for num in nums:
            m |= num

        return m+1