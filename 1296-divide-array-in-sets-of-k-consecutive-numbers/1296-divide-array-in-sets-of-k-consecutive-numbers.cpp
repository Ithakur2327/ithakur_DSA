class Solution {
public:
    bool isPossibleDivide(vector<int>&nums,int k) {
        if(nums.size()%k){
            return false;
        }

        map<int,int>freq;

        for(int x:nums){
            freq[x]++;
        }

        for(auto &it:freq){
            int start=it.first;
            int cnt=it.second;

            if(cnt==0){
                continue;
            }
            for(int i=0;i<k;i++){
                if(freq[start+i]<cnt){
                    return false;
                }
                freq[start+i]-=cnt;
            }
        }

        return true;
    }
};