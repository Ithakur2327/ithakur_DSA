class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0, ans = 0;

        for (int j = 0; j < n; j++) {
            while (nums[j] > 2 * nums[i]) {
                i++;
            }

            for (int k = i; k < j; k++) {
                ans = max(ans, nums[j] ^ nums[k]);
            }
        }

        return ans;
    }
};