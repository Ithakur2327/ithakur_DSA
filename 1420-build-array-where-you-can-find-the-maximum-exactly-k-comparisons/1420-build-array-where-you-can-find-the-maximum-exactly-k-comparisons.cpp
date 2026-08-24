class Solution{
public:
    int MOD=1e9+7;

    int solve(int pos,int mx,int cost,int n,int m,int k,vector<vector<vector<int>>>&dp){
        if(pos==n){
            if(cost==k)
                return 1;
            return 0;
        }

        if(cost>k)
            return 0;

        if(dp[pos][mx][cost]!=-1)
            return dp[pos][mx][cost];

        long long ans=0;

        for(int x=1;x<=m;x++){
            if(x>mx){
                ans+=solve(pos+1,x,cost+1,n,m,k,dp);
            }
            else{
                ans+=solve(pos+1,mx,cost,n,m,k,dp);
            }

            ans%=MOD;
        }

        return dp[pos][mx][cost]=ans;
    }

    int numOfArrays(int n,int m,int k){
        vector<vector<vector<int>>>dp(
            n,
            vector<vector<int>>(m+1,vector<int>(k+1,-1))
        );

        return solve(0,0,0,n,m,k,dp);
    }
};
