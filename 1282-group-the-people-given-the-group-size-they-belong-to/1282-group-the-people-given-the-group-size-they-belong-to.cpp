class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
          
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i< n; i++){
            int len = groupSizes[i];
            mp[len].push_back(i); 

            if(mp[len].size() == len){ 
                 ans.push_back(mp[len]);
                 mp[len] = {}; 
            }
        }
        return ans;
    }
};