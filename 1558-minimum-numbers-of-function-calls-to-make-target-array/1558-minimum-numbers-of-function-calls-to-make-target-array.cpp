class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0, maxi = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            count += __builtin_popcount(nums[i]);
            maxi = max(maxi , nums[i]);
        }
        while(maxi){
            if(maxi & 1) maxi--;
            else{
                count++;
                maxi >>= 1;
            }
        }
        return count;
    }
};