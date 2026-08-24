class Solution{
public:
    int solve(int i,int j,int diff,string&s,string&t,vector<vector<vector<int>>>&dp){
        if(i==s.size()||j==t.size())return 0;
        if(dp[i][j][diff]!=-1)return dp[i][j][diff];
        
        int ans=0;
        
        if(s[i]==t[j]){
            if(diff==1)ans=1+solve(i+1,j+1,diff,s,t,dp);
            else ans=solve(i+1,j+1,diff,s,t,dp);
        }
        else{
            if(diff==0)ans=1+solve(i+1,j+1,1,s,t,dp);
        }
        
        return dp[i][j][diff]=ans;
    }

    int countSubstrings(string s,string t){
        int n=s.size(),m=t.size();
        int ans=0;
        
        vector<vector<vector<int>>>dp(
            n,
            vector<vector<int>>(m,vector<int>(2,-1))
        );
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(i,j,0,s,t,dp);
            }
        }
        
        return ans;
    }
};
