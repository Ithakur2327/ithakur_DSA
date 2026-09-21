class Solution {
public:
    vector<long long> resultArray(vector<int>&nums,int k){
        vector<long long> dp(k,0),ans(k,0);

        for(int x:nums){
            x%=k;

            vector<long long> next(k,0);

            next[x]++;

            for(int r=0;r<k;r++){
                int nr=(r*x)%k;
                next[nr]+=dp[r];
            }

            dp=next;

            for(int r=0;r<k;r++)
                ans[r]+=dp[r];
        }

        return ans;
    }
};