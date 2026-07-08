class Solution {
public:
    int minOperations(vector<int>& nums) {
        int r = 2;
        int l = 0;
        int cnt = 0;

        while (r < nums.size()) {
            if (nums[l] == 0) {
                for (int k = l; k <= r; k++) {
                    nums[k] = 1 - nums[k]; 
                }
                cnt++; 
            }
            l++;
            r++;
        }

        for (int num : nums) {
            if (num == 0) return -1;
        }

        return cnt;
    }
};