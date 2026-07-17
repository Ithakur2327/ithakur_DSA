class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         int ans = 0;
        for(auto x : fruits){
            bool check = true;
            for(int i = 0; i<baskets.size(); i++){
                if(baskets[i] >= x){
                    baskets[i] = -1;
                    check = false;
                    break;
                }
            }
            if(check)
            ans++;
        }
        return ans;
    }
};