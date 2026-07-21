class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int a = nums[n - 1];
        int sum = 0;

        while (k) {
            sum += a;
            a += 1;
            k--;
        }

        return sum;
    }
};