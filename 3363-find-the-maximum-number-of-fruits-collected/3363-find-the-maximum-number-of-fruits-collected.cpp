class Solution {
public:
    int solve1(int i, int j, vector<vector<int>>& f, vector<vector<int>>& dp) {
        int n = f.size();

        if (i >= n || j >= n || j < 0)
            return -1e9;

        if (i == n - 1)
            return j == n - 1 ? f[i][j] : -1e9;

        if (j <= i)
            return -1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = f[i][j] + max({
            solve1(i + 1, j - 1, f, dp),
            solve1(i + 1, j, f, dp),
            solve1(i + 1, j + 1, f, dp)
        });
    }

    int solve2(int i, int j, vector<vector<int>>& f, vector<vector<int>>& dp) {
        int n = f.size();

        if (i >= n || j >= n || i < 0)
            return -1e9;

        if (j == n - 1)
            return i == n - 1 ? f[i][j] : -1e9;

        if (i <= j)
            return -1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = f[i][j] + max({
            solve2(i - 1, j + 1, f, dp),
            solve2(i, j + 1, f, dp),
            solve2(i + 1, j + 1, f, dp)
        });
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < n; i++)
            ans += fruits[i][i];

        ans += solve1(0, n - 1, fruits, dp1);
        ans += solve2(n - 1, 0, fruits, dp2);

        return ans - 2 * fruits[n - 1][n - 1];
    }
};
