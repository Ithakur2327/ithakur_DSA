class Solution{
public:
    int MOD=1e9+7;

    int solve(int i,int g1,int g2,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i==nums.size()){
            return g1==g2&&g1!=0;
        }

        if(dp[i][g1][g2]!=-1){
            return dp[i][g1][g2];
        }

        int ans=solve(i+1,g1,g2,nums,dp);

        int ng1=std::gcd(g1,nums[i]);
        ans=(ans+solve(i+1,ng1,g2,nums,dp))%MOD;

        int ng2=std::gcd(g2,nums[i]);
        ans=(ans+solve(i+1,g1,ng2,nums,dp))%MOD;

        return dp[i][g1][g2]=ans;
    }

    int subsequencePairCount(vector<int>&nums){
        int n=nums.size();
        vector<vector<vector<int>>>dp(
            n,
            vector<vector<int>>(201,vector<int>(201,-1))
        );

        return solve(0,0,0,nums,dp);
    }
};
