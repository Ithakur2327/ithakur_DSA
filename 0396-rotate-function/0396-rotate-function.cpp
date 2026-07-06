class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n = nums.size();

        long long total = 0;
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            curr += 1LL * i * nums[i];
        }

        long long ans = curr;

        for (int rot = 1; rot < n; rot++) {

            long long last = nums[n - rot];
            curr = curr + total - 1LL * n * last;
            ans = max(ans, curr);
        }

        return (int)ans;
    }
};