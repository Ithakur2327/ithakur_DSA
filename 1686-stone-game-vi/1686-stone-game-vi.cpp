class Solution {
public:
    int stoneGameVI(vector<int>&alice,vector<int>&bob) {
        vector<pair<int,int>>v;

        for(int i=0;i<alice.size();i++){
            v.push_back({alice[i]+bob[i],i});
        }
        sort(v.rbegin(),v.rend());
        int a=0;
        int b=0;

        for(int i=0;i<v.size();i++){
            if(i%2==0){
                a+=alice[v[i].second];
            }
            else{
                b+=bob[v[i].second];
            }
        }
        if(a>b){
            return 1;
        }
        if(a<b){
            return -1;
        }
        return 0;
    }
};