class Solution {
public:
    long long maximumValueSum(vector<int>&nums,int k,vector<vector<int>>&edges) {
        long long sum=0;
        int positive=0;
        int minPositive=INT_MAX;
        int maxNegative=INT_MIN;

        for(int num:nums){
            int gain=(num^k)-num;

            if(gain>0){
                positive++;
                sum+=num^k;
                minPositive=min(minPositive,gain);
            }
            else{
                sum+=num;
                maxNegative=max(maxNegative,gain);
            }
        }
        if(positive%2==0){
            return sum;
        }
        return max(sum-minPositive,sum+maxNegative);
    }
};