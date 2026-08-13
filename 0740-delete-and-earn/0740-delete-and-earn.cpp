class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int MAXV = 10000;

        vector<int> points(MAXV + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        int prev2 = 0;
        int prev1 = 0; 

        for (int i = 1; i <= MAXV; ++i) {
            int cur = max(prev1, prev2 + points[i]);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};