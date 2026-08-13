class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());

        int ans = 0;
        int i = 0;
        int n = answers.size();

        while (i < n) {
            int x = answers[i];
            int groupSize = x + 1;

            int cnt = 0;
            while (i < n && answers[i] == x && cnt < groupSize) {
                i++;
                cnt++;
            }
            ans += groupSize;
        }
        return ans;
    }
};