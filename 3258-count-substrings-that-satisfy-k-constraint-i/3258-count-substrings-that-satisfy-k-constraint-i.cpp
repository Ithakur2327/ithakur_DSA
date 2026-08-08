class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int zeros = 0, ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '0')
                    zeros++;
                else
                    ones++;

                if (zeros <= k || ones <= k)
                    ans++;
            }
        }

        return ans;
    }
};