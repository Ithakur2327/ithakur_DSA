class Solution {
public:
    const long long MOD=1e9+7;
    long long dp[5001][2];

    long long solve(int row,int n,int type){
        if(row==n){
            return 1;
        }

        if(dp[row][type]!=-1){
            return dp[row][type];
        }

        if(type==0){
            return dp[row][type]=(
                3*solve(row+1,n,0)+
                2*solve(row+1,n,1)
            )%MOD;
        }

        return dp[row][type]=(
            2*solve(row+1,n,0)+
            2*solve(row+1,n,1)
        )%MOD;
    }

    int numOfWays(int n){
        memset(dp,-1,sizeof(dp));

        long long aba=solve(1,n,0);
        long long abc=solve(1,n,1);

        return (6*aba+6*abc)%MOD;
    }
};