class Solution {
public:
    int countSubstrings(string s) {
        int totalcnt = 0;
        for (int i = 0; i < s.length(); i++) {
            // cnt palindromes with odd length
            totalcnt += extendPalindrome(s, i, i);
            // cnt palindromes with even length
            totalcnt += extendPalindrome(s, i, i + 1);
        }
        return totalcnt;
    }

private:
    int extendPalindrome(const string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 &&r < s.length() && s[l] == s[r]) {
            cnt++;
            l--;
           r++;
        }
        return cnt;
    }
};