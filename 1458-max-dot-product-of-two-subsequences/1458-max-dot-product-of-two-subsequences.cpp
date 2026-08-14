class Solution {
public:
    int maxDotProduct(vector<int>&nums1,vector<int>&nums2) {
        int n=nums1.size();
        int m=nums2.size();

        const int NEG=-1e9;

        vector<int>dp(m+1,NEG);

        for(int i=n-1;i>=0;i--){
            vector<int>curr(m+1,NEG);

            for(int j=m-1;j>=0;j--){
                int take=nums1[i]*nums2[j];

                if(dp[j+1]!=NEG){
                    take=max(take,take+dp[j+1]);
                }

                int skip1=dp[j];
                int skip2=curr[j+1];

                curr[j]=max({take,skip1,skip2});
            }

            dp=curr;
        }

        return dp[0];
    }
};