class Solution {
public:
    int numEnclaves(vector<vector<int>>&grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        queue<pair<int,int>>q;
        for(int row=0;row<rows;row++) {
            for(int col=0;col<cols;col++) {
                if(row==0||col==0||row==rows-1||col==cols-1) {
                    if(grid[row][col]==1) {
                        visited[row][col]=1;
                        q.push({row,col});
                    }
                }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()) {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int newRow=row+dr[i];
                int newCol=col+dc[i];
                if(newRow>=0&&newRow<rows&&newCol>=0&&newCol<cols&&grid[newRow][newCol]==1&&visited[newRow][newCol]==0) {
                    visited[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
        int count=0;
        for(int row=0;row<rows;row++) {
            for(int col=0;col<cols;col++) {
                if(grid[row][col]==1&&visited[row][col]==0) {
                    count++;
                }
            }
        }
        return count;
    }
};