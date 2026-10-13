class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>a;
        for(int x:nums) a.push_back(x*x);
        sort(a.begin(),a.end());
        long long ans=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(i<n/2) ans-=a[i];
            else ans+=a[i];
        }
        return ans;
    }
};