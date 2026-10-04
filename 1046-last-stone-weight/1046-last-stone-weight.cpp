class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int>pq;
        for(int stone:stones){
            pq.push(stone);
        }
        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(b==a){
                continue;
            }
            pq.push(a-b);
        }
        return (pq.size()==1)?pq.top():0;
    }
};