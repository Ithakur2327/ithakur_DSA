class Solution{
public:
    bool isPalindrome(int left,int right,string& s){
        while(left<right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }

    int solve(int index,string& s,vector<int>& dp){
        if(index==s.size())return 0;

        if(dp[index]!=-1)return dp[index];

        int ans=INT_MAX;

        for(int j=index;j<s.size();j++){
            if(isPalindrome(index,j,s)){
                int partitions=1+solve(j+1,s,dp);
                ans=min(ans,partitions);
            }
        }

        return dp[index]=ans;
    }

    int minCut(string s){
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1;
    }
};
