class Solution {
public:
    bool divideArray(vector<int>& nums) {
         unordered_map<int, int> counts;
        for (int x : nums) {
            counts[x]++;
        }
        for (auto& [val, freq] : counts) {
            if (freq % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};