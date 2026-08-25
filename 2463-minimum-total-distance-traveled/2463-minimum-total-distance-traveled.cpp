#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(int i,int j,vector<int>& r,vector<vector<int>>& a,vector<vector<long long>>& dp){
        if(i==r.size()) return 0;
        if(j==a.size()) return 1e18;
        if(dp[i][j]!=-1) return dp[i][j];

        long long skip=f(i,j+1,r,a,dp);
        long long use=1e18;
        long long cost=0;

        for(int k=1;k<=a[j][1]&&i+k<=r.size();k++){
            cost+=abs(r[i+k-1]-a[j][0]);
            use=min(use,cost+f(i+k,j+1,r,a,dp));
        }

        return dp[i][j]=min(skip,use);
    }

    long long minimumTotalDistance(vector<int>& r,vector<vector<int>>& a){
        sort(r.begin(),r.end());
        sort(a.begin(),a.end());

        int n=r.size(),m=a.size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));

        return f(0,0,r,a,dp);
    }
};
