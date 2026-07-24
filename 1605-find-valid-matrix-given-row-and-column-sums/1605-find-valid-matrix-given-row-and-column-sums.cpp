class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int i = 0, j = 0, m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n , 0));
        while(i < m && j < n){
            int val = min(rowSum[i] , colSum[j]);
            res[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
            if(rowSum[i] < colSum[j]) i++;
            else j++;
        }
        return res;
    }
};