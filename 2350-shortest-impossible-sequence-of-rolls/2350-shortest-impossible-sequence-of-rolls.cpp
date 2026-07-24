class Solution {
public:
    int shortestSequence(vector<int>&rolls,int k) {
        unordered_set<int>seen;
        int completedSets=0;

        for(int roll:rolls){
            seen.insert(roll);

            if(seen.size()==k){
                completedSets++;
                seen.clear();
            }
        }

        return completedSets+1;
    }
};