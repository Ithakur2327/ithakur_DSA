class Solution {
public:
    long long minimumReplacement(vector<int>&nums) {
        long long ans=0;
        int limit=nums.back();

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=limit){
                limit=nums[i];
            }
            else{
                int parts=(nums[i]+limit-1)/limit;
                ans+=parts-1;
                limit=nums[i]/parts;
            }
        }
        return ans;
    }
};