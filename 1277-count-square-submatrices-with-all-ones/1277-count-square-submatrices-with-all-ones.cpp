class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (matrix[i][j] == 0) {
            return dp[i][j] = 0;
        }

        int top = solve(i - 1, j, matrix, dp);
        int left = solve(i, j - 1, matrix, dp);
        int diagonal = solve(i - 1, j - 1, matrix, dp);

        return dp[i][j] = 1 + min({top, left, diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<vector<int>> dp(
            rows,
            vector<int>(columns, -1)
        );

        int answer = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                answer += solve(i, j, matrix, dp);
            }
        }

        return answer;
    }
};
