class Solution{
public:
    pair<int,int> solve(int index,vector<int>& arr,vector<pair<int,int>>& dp){
        if(dp[index].first!=-1)return dp[index];

        int bestLength=1;
        int ways=1;

        for(int previous=0;previous<index;previous++){
            if(arr[previous]<arr[index]){
                auto previousState=solve(previous,arr,dp);
                int candidateLength=previousState.first+1;

                if(candidateLength>bestLength){
                    bestLength=candidateLength;
                    ways=previousState.second;
                }
                else if(candidateLength==bestLength){
                    ways+=previousState.second;
                }
            }
        }

        return dp[index]={bestLength,ways};
    }

    int findNumberOfLIS(vector<int>& arr){
        int n=arr.size();
        vector<pair<int,int>> dp(n,{-1,-1});

        int overallLength=0;
        int totalWays=0;

        for(int i=0;i<n;i++){
            auto current=solve(i,arr,dp);

            if(current.first>overallLength){
                overallLength=current.first;
                totalWays=current.second;
            }
            else if(current.first==overallLength){
                totalWays+=current.second;
            }
        }

        return totalWays;
    }
};
