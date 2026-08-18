class Solution{
public:
    vector<vector<int>>dp;
    int solve(int l,int r,string&s){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r])return dp[l][r]=solve(l+1,r-1,s);
        return dp[l][r]=1+min(solve(l+1,r,s),solve(l,r-1,s));
    }
    int minInsertions(string s){
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,n-1,s);
    }
};