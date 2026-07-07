class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), i = k, j = k, ans = nums[k], minc = nums[k];

        while (i > 0 || j < n - 1) {
            if (i == 0 || nums[i - 1] < nums[j + 1]) j++;
            else i--;
            minc = min(minc, min(nums[i], nums[j]));
            ans = max(ans, minc * (j - i + 1));
        }
        return ans;
    }
};