class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0, end = nums.size() - 1;
        int maxPair = 0;

        while (start < end) {
            int pairSum = nums[start] + nums[end];
            maxPair = max(maxPair, pairSum);
            start++;
            end--;
        }

        return maxPair;
    }
};