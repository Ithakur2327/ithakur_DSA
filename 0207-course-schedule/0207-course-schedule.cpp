class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(adj, neighbour, visited, pathVisited)) {
                    return true;
                }
            }
            else if (pathVisited[neighbour]) {
                return true;
            }
        }

        pathVisited[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, pathVisited)) {
                    return false;
                }
            }
        }

        return true;
    }
};