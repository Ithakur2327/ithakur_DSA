class Solution{
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int dir){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int ni=i+dir;

        if(ni<0||ni>=grid.size())
            return dp[i][j]=1;

        int left=solve(ni,j-1,grid,dp,dir);
        int mid=solve(ni,j,grid,dp,dir);
        int right=solve(ni,j+1,grid,dp,dir);

        return dp[i][j]=1+min({left,mid,right});
    }

    int countPyramids(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;

        vector<vector<int>>dp1(m,vector<int>(n,-1));
        vector<vector<int>>dp2(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans+=solve(i,j,grid,dp1,1)-1;
                    ans+=solve(i,j,grid,dp2,-1)-1;
                }
            }
        }

        return ans;
    }
};
