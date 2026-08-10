class Solution {
public:
    vector<int> recoverArray(vector<int>&nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size()/2;

        for(int i=1;i<nums.size();i++){
            int diff=nums[i]-nums[0];

            if(diff<=0||diff%2!=0){
                continue;
            }

            int k=diff/2;

            unordered_map<int,int>freq;

            for(int x:nums){
                freq[x]++;
            }

            vector<int>ans;

            for(int x:nums){
                if(freq[x]==0){
                    continue;
                }

                int y=x+2*k;

                if(freq[y]==0){
                    break;
                }

                ans.push_back(x+k);

                freq[x]--;
                freq[y]--;
            }

            if(ans.size()==n){
                return ans;
            }
        }

        return {};
    }
};