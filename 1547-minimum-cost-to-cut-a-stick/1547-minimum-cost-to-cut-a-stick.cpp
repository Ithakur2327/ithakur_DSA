class Solution{
public:
    int solve(int left,int right,vector<int>& cuts,vector<vector<int>>& dp){
        if(left+1==right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];

        int ans=INT_MAX;

        for(int k=left+1;k<right;k++){
            int cost=cuts[right]-cuts[left]
                    +solve(left,k,cuts,dp)
                    +solve(k,right,cuts,dp);

            ans=min(ans,cost);
        }
        return dp[left][right]=ans;
    }

    int minCost(int n,vector<int>& cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));

        return solve(0,m-1,cuts,dp);
    }
};
