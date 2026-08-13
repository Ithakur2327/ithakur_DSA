class Solution {
public:
    void helper(vector<int>& nums, vector<int>& curr,
                set<vector<int>>& result, int ind, int prev)
    {
        if(ind == nums.size())
        {
            if(curr.size() >= 2)
                result.insert(curr);
            return;
        }

        // Not Take
        helper(nums, curr, result, ind + 1, prev);

        // Take
        if(nums[ind] >= prev)
        {
            curr.push_back(nums[ind]);

            helper(nums, curr, result, ind + 1, nums[ind]);

            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int>> result;
        vector<int> curr;

        helper(nums, curr, result, 0, INT_MIN);

        return vector<vector<int>>(result.begin(), result.end());
    }
};