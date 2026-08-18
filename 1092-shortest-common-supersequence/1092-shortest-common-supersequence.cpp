#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = 1 + min(
            solve(i - 1, j, s1, s2, dp),
            solve(i, j - 1, s1, s2, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, -1)
        );

        solve(n, m, str1, str2, dp);

        string ans;
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (solve(i - 1, j, str1, str2, dp) <=
                     solve(i, j - 1, str1, str2, dp)) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};