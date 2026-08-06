class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        totalDistinct = len(set(nums))

        freq = Counter()
        left = 0
        distinct = 0
        ans = 0

        for right in range(n):
            if freq[nums[right]] == 0:
                distinct += 1
            freq[nums[right]] += 1

            while distinct == totalDistinct:
                ans += n - right

                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    distinct -= 1
                left += 1

        return ans