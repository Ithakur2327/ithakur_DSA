class Solution{
public:
    int MOD=1e9+7;

    int solve(int pos,int fuel,vector<int>&locations,int finish,vector<vector<int>>&dp){
        if(fuel<0)
            return 0;

        if(dp[pos][fuel]!=-1)
            return dp[pos][fuel];

        long long ans=0;

        if(pos==finish)
            ans=1;

        for(int i=0;i<locations.size();i++){
            if(i==pos)
                continue;

            int cost=abs(locations[pos]-locations[i]);

            if(cost<=fuel){
                ans+=solve(i,fuel-cost,locations,finish,dp);
                ans%=MOD;
            }
        }

        return dp[pos][fuel]=ans;
    }

    int countRoutes(vector<int>&locations,int start,int finish,int fuel){
        vector<vector<int>>dp(
            locations.size(),
            vector<int>(fuel+1,-1)
        );

        return solve(start,fuel,locations,finish,dp);
    }
};
