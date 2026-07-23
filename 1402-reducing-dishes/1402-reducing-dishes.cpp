class Solution {
public:
    int maxSatisfaction(vector<int>&satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        int prefix=0;
        int ans=0;

        for(int i=satisfaction.size()-1;i>=0;i--){
            prefix+=satisfaction[i];

            if(prefix<=0){
                break;
            }

            ans+=prefix;
        }

        return ans;
    }
};