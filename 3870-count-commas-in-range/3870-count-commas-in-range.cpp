class Solution {
public:
    int countCommas(int n) {
        int t=0;
        for(int i=1;i<=n;i++){
            int dg=to_string(i).size();
            t+=(dg-1)/3;
        }
        return t;
    }
};