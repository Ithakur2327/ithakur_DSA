class Solution {
public:
    long long maxSpending(vector<vector<int>>&values) {
        int m=values.size();
        int n=values[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        for(int i=0;i<m;i++){
            pq.push({values[i][n-1],i,n-1});
        }

        long long day=1;
        long long ans=0;

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int value=curr[0];
            int row=curr[1];
            int col=curr[2];

            ans+=1LL*value*day;
            day++;

            if(col>0){
                pq.push({values[row][col-1],row,col-1});
            }
        }

        return ans;
    }
};