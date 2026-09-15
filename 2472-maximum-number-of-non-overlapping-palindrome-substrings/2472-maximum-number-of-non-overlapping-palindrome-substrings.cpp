class Solution {
public:
    int maxPalindromes(string s,int k){
        int n=s.size();
        vector<int>dp(n+1,0);

        for(int i=k;i<=n;i++){
            dp[i]=dp[i-1];

            int left=i-k;
            int right=i-1;

            bool ok=true;
            while(left<right){
                if(s[left]!=s[right]){
                    ok=false;
                    break;
                }
                left++;
                right--;
            }

            if(ok)
                dp[i]=max(dp[i],dp[i-k]+1);

            if(i>=k+1){
                left=i-k-1;
                right=i-1;
                ok=true;

                while(left<right){
                    if(s[left]!=s[right]){
                        ok=false;
                        break;
                    }
                    left++;
                    right--;
                }

                if(ok)
                    dp[i]=max(dp[i],dp[i-k-1]+1);
            }
        }

        return dp[n];
    }
};