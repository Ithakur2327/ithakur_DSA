class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (char c : tasks)
            freq[c - 'A']++;

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];
        int idle = (maxFreq - 1) * n;

        for (int i = 24; i >= 0 && idle > 0; i--) {
            idle -= min(maxFreq - 1, freq[i]);
        }

        idle = max(0, idle);

        return tasks.size() + idle;
    }
};