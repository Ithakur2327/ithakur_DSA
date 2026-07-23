class Solution {
public:
    long long putMarbles(vector<int>&weights,int k) {
        vector<long long>pairs;

        for(int i=0;i<weights.size()-1;i++){
            pairs.push_back((long long)weights[i]+weights[i+1]);
        }

        sort(pairs.begin(),pairs.end());
        long long ans=0;

        int left=0;
        int right=pairs.size()-1;
        while(k>1){
            ans+=pairs[right]-pairs[left];
            left++;
            right--;
            k--;
        }
        return ans;
    }
};