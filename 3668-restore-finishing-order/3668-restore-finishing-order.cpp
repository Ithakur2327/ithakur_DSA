class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(), friends.end());

        vector<int> res;
        res.reserve(friends.size());

        for (int x : order) {
            if (st.contains(x))
                res.push_back(x);
        }
        return res;
    }
};