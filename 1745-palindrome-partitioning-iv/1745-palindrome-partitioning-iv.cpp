class Solution {
public:
    bool f(int i,int k,string& s,vector<vector<int>>& dp){
        int n=s.size();

        if(k==0) return i==n;
        if(n-i<k) return false;

        if(dp[i][k]!=-1) return dp[i][k];

        for(int j=i;j<n;j++){
            if(p(i,j,s)){
                if(f(j+1,k-1,s,dp))
                    return dp[i][k]=1;
            }
        }

        return dp[i][k]=0;
    }

    bool p(int l,int r,string& s){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool checkPartitioning(string s){
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return f(0,3,s,dp);
    }
};
