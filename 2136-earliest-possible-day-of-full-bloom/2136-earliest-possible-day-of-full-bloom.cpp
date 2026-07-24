class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>vpp(n);
        for(int i=0;i<n;i++){
            vpp[i]={growTime[i],plantTime[i]};
        }
        sort(vpp.rbegin(),vpp.rend());
        int ans=0;
        int sum=0;
       for(int i=0;i<n;i++){
          sum+=vpp[i].second;
          ans=max(ans,sum+vpp[i].first);
}
        return ans;
    }
};