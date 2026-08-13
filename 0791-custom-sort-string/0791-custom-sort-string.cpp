class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;
        // Characters according to custom order
        for (char c : order) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }
        // Characters not present in order
        for (char c = 'a'; c <= 'z'; c++) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }
        return ans;
    }
};