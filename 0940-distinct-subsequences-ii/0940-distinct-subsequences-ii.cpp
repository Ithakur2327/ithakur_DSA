class Solution {
public:
    const long long MOD=1e9+7;
    vector<long long>dp;
    vector<int>last;

    long long solve(int i,string&s){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];

        int c=s[i-1]-'a';
        long long ans=(2*solve(i-1,s))%MOD;

        if(last[c]!=-1)
            ans=(ans-solve(last[c],s)+MOD)%MOD;

        last[c]=i-1;

        return dp[i]=ans;
    }

    int distinctSubseqII(string s){
        int n=s.size();
        dp.assign(n+1,-1);
        last.assign(26,-1);

        return (solve(n,s)-1+MOD)%MOD;
    }
};