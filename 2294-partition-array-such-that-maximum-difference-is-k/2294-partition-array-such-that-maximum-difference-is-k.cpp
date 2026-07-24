class Solution {
public:
    int partitionArray(vector<int>&nums,int k) {
        sort(nums.begin(),nums.end());

        int answer=1;
        int minimum=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]-minimum>k){
                answer++;
                minimum=nums[i];
            }
        }

        return answer;
    }
};