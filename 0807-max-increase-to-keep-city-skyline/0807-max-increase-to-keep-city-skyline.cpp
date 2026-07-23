class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(); //n*n
        vector<int>row(n,INT_MIN);
        vector<int>col(n,INT_MIN);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                row[r]=max(row[r],grid[r][c]);
                col[c]=max(col[c],grid[r][c]);
            }
        }
    
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                ans+=min(row[r],col[c])-grid[r][c];
            }
        }
        return ans;
    }
};