class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r)
            return 0;

        int &res = dp[l][r][k];
        if (res != -1)
            return res;

        // Extend boxes[r] with consecutive equal boxes immediately before it.
        int rr = r;
        int kk = k;

        while (rr > l && boxes[rr - 1] == boxes[r]) {
            --rr;
            ++kk;
        }

        // Remove this group now.
        res = solve(boxes, l, rr - 1, 0) + (kk + 1) * (kk + 1);

        // Try to merge it with an earlier box of the same color.
        for (int i = l; i < rr; ++i) {
            if (boxes[i] == boxes[r]) {
                res = max(
                    res,
                    solve(boxes, l, i, kk + 1) +
                    solve(boxes, i + 1, rr - 1, 0)
                );
            }
        }

        return res;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};