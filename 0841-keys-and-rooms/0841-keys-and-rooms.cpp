class Solution {
    void dfs(vector<vector<int>>& rooms,int room , vector<bool>&visited){
        visited[room]=true;
        for(int x : rooms[room]){
            if(!visited[x])
            dfs(rooms,x,visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms,0,visited);
        for(bool room : visited){
            if(!room)return false;
        }
        return true;
    }
};