class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int, unordered_set<int>> mpp;
        for(auto it:logs)
            mpp[it[0]].insert(it[1]);
        for(auto it:mpp)
           ans[it.second.size()-1]++;
        return ans;        
    }
};