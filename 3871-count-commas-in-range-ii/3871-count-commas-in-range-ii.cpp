class Solution {
public:
    long long countCommas(long long n) {
        long long k=n;
        long long ans=0,s=1;

        for(int i=1;i<=16;i++){
            long long e=s*10-1;
            if(k<s)break;

            long long up=min(k,e);
            long long cnt=up-s+1;
            ans+=cnt*((i-1)/3);
            s*=10;
        }
        return ans;

    }
};