class Solution {
public:
    int m, n;
    int ways;
    int nonObstacles;

    vector<vector<int>> direction{{1,0},{0,1},{-1,0},{0,-1}};

    void solve(vector<vector<int>>& grid, int cnt, int i, int j) {

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
            return;

        if(grid[i][j] == 2){
            if(cnt == nonObstacles)
                ways++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        for(auto &dir : direction){
            solve(grid, cnt + 1, i + dir[0], j + dir[1]);
        }

        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        ways = 0;
        nonObstacles = 0;

        int sx = 0, sy = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] != -1)
                    nonObstacles++;

                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }

        solve(grid, 1, sx, sy);

        return ways;
    }
};