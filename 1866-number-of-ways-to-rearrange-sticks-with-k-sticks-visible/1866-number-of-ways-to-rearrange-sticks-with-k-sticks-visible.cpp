class Solution {
public:
    const int mod=1e9+7;

    long long f(int n,int k,vector<vector<long long>>& dp){
        if(k==0) return 0;
        if(n==0) return 0;
        if(k>n) return 0;
        if(n==1) return k==1;

        if(dp[n][k]!=-1) return dp[n][k];

        long long a=f(n-1,k-1,dp);
        long long b=(n-1)*f(n-1,k,dp)%mod;

        return dp[n][k]=(a+b)%mod;
    }

    int rearrangeSticks(int n,int k){
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,-1));
        return f(n,k,dp);
    }
};
