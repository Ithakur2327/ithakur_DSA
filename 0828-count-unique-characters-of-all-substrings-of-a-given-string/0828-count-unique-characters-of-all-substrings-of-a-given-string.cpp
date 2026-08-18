#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> last(26, -1);
        vector<int> contribution(26, 0);

        long long dp = 0;
        long long ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'A';

            dp -= contribution[x];

            contribution[x] = i - last[x];

            dp += contribution[x];

            last[x] = i;

            ans += dp;
        }

        return ans;
    }
};