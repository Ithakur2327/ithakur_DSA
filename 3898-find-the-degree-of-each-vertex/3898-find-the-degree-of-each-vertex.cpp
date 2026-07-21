class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> ans(m,0);
        for(int i = 0; i<m; i++){
            for(int x : matrix[i]){
                if(x == 1) ans[i]++;
            }
        }
        return ans;
    }
};