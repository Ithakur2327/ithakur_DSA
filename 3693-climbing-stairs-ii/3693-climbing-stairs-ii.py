class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [float('inf')] * (n + 1)
        dp[0] = 0

        for i in range(1, n + 1):
            for j in range(1, 4):
                prev = i - j

                if prev >= 0:
                    currJumpCost = costs[i - 1] + j * j
                    totalCost = dp[prev] + currJumpCost

                    dp[i] = min(dp[i], totalCost)

        return dp[n]