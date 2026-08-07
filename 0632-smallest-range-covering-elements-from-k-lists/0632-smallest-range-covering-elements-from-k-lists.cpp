class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;

        for(int i=0;i<nums.size();i++)
            for(int x:nums[i])
                v.push_back({x,i});

        sort(v.begin(),v.end());

        unordered_map<int,int> mp;
        int l=0,c=0,k=nums.size();
        vector<int> ans={0,INT_MAX};

        for(int r=0;r<v.size();r++){
            if(mp[v[r].second]==0)
                c++;

            mp[v[r].second]++;

            while(c==k){
                if(v[r].first-v[l].first<ans[1]-ans[0]){
                    ans[0]=v[l].first;
                    ans[1]=v[r].first;
                }

                mp[v[l].second]--;

                if(mp[v[l].second]==0)
                    c--;

                l++;
            }
        }

        return ans;
    }
};