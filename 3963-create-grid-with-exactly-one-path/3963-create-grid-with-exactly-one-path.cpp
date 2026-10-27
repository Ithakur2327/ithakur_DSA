class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
       int r=0,c=0;
        grid[0][0]='.';
        while(c+1<n){
            c++;
            grid[r][c]='.';
            if(r+1<m){
                r++;
                grid[r][c]='.';
            }
        }
        while(r+1<m){
            r++;
            grid[r][c]='.';
        }
        return grid;
        
        
    }
};