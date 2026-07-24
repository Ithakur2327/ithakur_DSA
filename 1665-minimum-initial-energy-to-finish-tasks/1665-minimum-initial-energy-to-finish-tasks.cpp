class Solution {
public:
    int minimumEffort(vector<vector<int>>&tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return a[1]-a[0]>b[1]-b[0];
        });

        int answer=0;
        int energy=0;

        for(auto &task:tasks){
            if(energy<task[1]){
                answer+=task[1]-energy;
                energy=task[1];
            }

            energy-=task[0];
        }

        return answer;
    }
};