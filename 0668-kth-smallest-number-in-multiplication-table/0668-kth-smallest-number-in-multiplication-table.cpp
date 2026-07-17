class Solution {
public:
    bool pos(int mid,int m,int n,int k)
    {
        int ct=0,i;
        for(i=1;i<=m;i++)
        {
            ct+=min(n,mid/i);
        }
        return ct>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int lo=1,hi=m*n;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(pos(mid,m,n,k))
            hi=mid-1;
            else
            lo=mid+1;
        }
        return lo;
    }
};