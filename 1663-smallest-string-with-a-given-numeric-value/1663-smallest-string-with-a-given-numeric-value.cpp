class Solution {
public:
    string getSmallestString(int n,int k) {
        string ans(n,'a');
        int extra=k-n;

        for(int i=n-1;i>=0&&extra>0;i--){
            int add=min(25,extra);
            ans[i]+=add;
            extra-=add;
        }

        return ans;
    }
};