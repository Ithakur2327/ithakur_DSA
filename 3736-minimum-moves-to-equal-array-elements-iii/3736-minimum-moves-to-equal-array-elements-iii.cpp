class Solution {
public:
    int minMoves(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int diff = largest - nums[i];
            sum += diff;
        }

        return sum;
    }
};