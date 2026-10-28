class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> mq=grid;
        int m=grid.size() , n= grid[0].size();
         const int maxx=1024;

        vector<vector<bitset<maxx>>> dp(m,vector<bitset<maxx>>(n));
        dp[0][0].set(grid[0][0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                bitset<maxx> poss;
                if(i>0) poss |= dp[i-1][j];
                if(j>0) poss |= dp[i][j-1];
                for(int x=0;x<maxx;x++){
                    if(poss[x]){
                        dp[i][j].set(x^grid[i][j]);
                    }
                }
            }
        }
        for(int y=0;y<maxx;y++){
            if(dp[m-1][n-1][y]){
                return y;
            }
        }
        return 0;
    }
};