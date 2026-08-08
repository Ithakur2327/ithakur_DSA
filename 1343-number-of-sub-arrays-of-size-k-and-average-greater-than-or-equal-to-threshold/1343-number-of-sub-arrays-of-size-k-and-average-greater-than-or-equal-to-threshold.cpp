class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int windowSum = 0;
        int count = 0;

        // First window
        for(int i = 0; i < k; i++) {
          windowSum += arr[i];
    }

        int requiredSum = k * threshold;

        if(windowSum >= requiredSum) {
        count++;
    }

        // Remaining windows
        for(int i = k; i < n; i++) {

        // Remove old element
        windowSum -= arr[i - k];

        // Add new element
        windowSum += arr[i];

        if(windowSum >= requiredSum) {
            count++;
        }
    }
        return count;
    }
};