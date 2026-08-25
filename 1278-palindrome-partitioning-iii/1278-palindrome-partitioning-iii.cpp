class Solution {
public:
    int f(int i,int k,string& s,vector<vector<int>>& dp){
        if(k==1) return cost(i,s.size()-1,s);
        if(dp[i][k]!=-1) return dp[i][k];

        int ans=1e9;

        for(int j=i;j<s.size()-k+1;j++){
            ans=min(ans,cost(i,j,s)+f(j+1,k-1,s,dp));
        }

        return dp[i][k]=ans;
    }

    int cost(int l,int r,string& s){
        int x=0;
        while(l<r){
            if(s[l]!=s[r]) x++;
            l++;
            r--;
        }
        return x;
    }

    int palindromePartition(string s,int k){
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(0,k,s,dp);
    }
};
