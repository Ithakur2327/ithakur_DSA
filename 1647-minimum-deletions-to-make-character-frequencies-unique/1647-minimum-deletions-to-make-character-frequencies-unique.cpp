class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26);

        for(char c:s){freq[c-'a']++;}
        unordered_set<int>used;
        int ans=0;

        for(int f:freq){
            while(f>0&&used.count(f)){
                f--;
                ans++;
            }

            if(f>0){
                used.insert(f);
            }
        }
        return ans;
    }
};