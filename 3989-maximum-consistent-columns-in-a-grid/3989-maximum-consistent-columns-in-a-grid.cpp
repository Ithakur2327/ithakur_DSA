class Solution{
public:
    int maxConsistentColumns(vector<vector<int>>&grid,int limit){
        int m=grid.size();
        int n=grid[0].size();

        vector<int>dp(n,1);
        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                bool ok=true;

                for(int r=0;r<m;r++){
                    if(abs(grid[r][i]-grid[r][j])>limit){
                        ok=false;
                        break;
                    }
                }

                if(ok){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

            ans=max(ans,dp[i]);
        }

        return ans;
    }
};
