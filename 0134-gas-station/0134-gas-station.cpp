class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalBalance = 0;  
        int currentBalance = 0;  
        int startIndex = 0;      

        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];
            totalBalance += gain;
            currentBalance += gain;

            if (currentBalance < 0) {
                startIndex = i + 1;   
                currentBalance = 0;   
            }
        }

        return (totalBalance < 0) ? -1 : startIndex;
    }
};