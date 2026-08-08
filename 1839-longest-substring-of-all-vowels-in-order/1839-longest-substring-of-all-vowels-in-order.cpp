class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        int start = 0;
        int distinct = 1;

        for (int i = 1; i < word.size(); ++i) {
            if (word[i] < word[i - 1]) {
                // Order is broken.
                start = i;
                distinct = 1;
            }
            else if (word[i] > word[i - 1]) {
                // Moved to the next vowel.
                ++distinct;
            }

            if (distinct == 5) {
                ans = max(ans, i - start + 1);
            }
        }
        return ans;
    }
};