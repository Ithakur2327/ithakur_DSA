class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<int, int> mpp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }

        int lastocc = mpp[s[n - 1]];

        for (auto it : mpp) {
            if (it.second != lastocc) {
                return false;
            }
        }

        return true;
    }
};