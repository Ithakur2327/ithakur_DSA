class Solution {
public:
    vector<int> rearrangeArray(vector<int>&nums) {
        sort(nums.begin(),nums.end());

        vector<int>ans;
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            ans.push_back(nums[left++]);

            if(left<=right){
                ans.push_back(nums[right--]);
            }
        }

        return ans;
    }
};