class Solution {
public:
    vector<int>topologicalSort(int k,vector<vector<int>>&conditions) {
        vector<vector<int>>adj(k+1);
        vector<int>indegree(k+1,0);
        for(auto &edge:conditions) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        vector<int>order;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(int neighbour:adj[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) {
                    q.push(neighbour);
                }
            }
        }
        if(order.size()!=k) {
            return {};
        }
        return order;
    }

    vector<vector<int>>buildMatrix(int k,vector<vector<int>>&rowConditions,vector<vector<int>>&colConditions) {
        vector<int>rowOrder=topologicalSort(k,rowConditions);
        vector<int>colOrder=topologicalSort(k,colConditions);

        if(rowOrder.empty()||colOrder.empty()) {
            return {};
        }

        vector<int>rowPos(k+1);
        vector<int>colPos(k+1);

        for(int i=0;i<k;i++) {
            rowPos[rowOrder[i]]=i;
            colPos[colOrder[i]]=i;
        }

        vector<vector<int>>matrix(k,vector<int>(k,0));

        for(int num=1;num<=k;num++) {
            matrix[rowPos[num]][colPos[num]]=num;
        }

        return matrix;
    }
};