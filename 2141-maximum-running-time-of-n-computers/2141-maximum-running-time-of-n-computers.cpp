class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;

        long long l=0, r=total / n, ans=0;
        while (l <= r) {
            long long mid = (l + r)/2;

            long long usable = 0;
            for (long long b : batteries) {
                usable += min(b, mid);
            }

            if (usable >= mid * n) {
                ans=mid;
                l=mid + 1;
            }
            else {
                r=mid - 1;
            }
        }
        return ans;
    }
};