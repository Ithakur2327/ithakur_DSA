class Solution {
public:
    int numTeams(vector<int>&rating) {
        int n=rating.size();
        int ans=0;

        for(int j=0;j<n;j++){
            int smallerLeft=0;
            int greaterLeft=0;
            int smallerRight=0;
            int greaterRight=0;

            for(int i=0;i<j;i++){
                if(rating[i]<rating[j]){
                    smallerLeft++;
                }
                else{
                    greaterLeft++;
                }
            }

            for(int k=j+1;k<n;k++){
                if(rating[k]<rating[j]){
                    smallerRight++;
                }
                else{
                    greaterRight++;
                }
            }

            ans+=smallerLeft*greaterRight;
            ans+=greaterLeft*smallerRight;
        }

        return ans;
    }
};