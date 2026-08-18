class Solution {
public:
    vector<vector<int>> dp;
    vector<int> a;

    int solve(int l, int r) {
        if (l + 1 == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for (int k = l + 1; k < r; k++) {
            ans = max(ans,
                solve(l, k) +
                a[l] * a[k] * a[r] +
                solve(k, r)
            );
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        a.resize(n + 2, 1);

        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }

        dp.assign(n + 2, vector<int>(n + 2, -1));

        return solve(0, n + 1);
    }
};