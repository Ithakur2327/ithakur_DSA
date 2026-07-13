class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> seen = {0};
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            if (seen.count(sum - target)) {
                count++;
                seen.clear();       
                seen.insert(0);     
                sum = 0;            
            } else {
                seen.insert(sum);
            }
        }

        return count;
    }
};