class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> solution;
        for(int i=0; i<n-2; i++){
            int target = -nums[i];
            int l = i+1, r = nums.size()-1;

            if(i>0 && nums[i] == nums[i-1]) continue;

            while(l<r){
                int need = nums[l] + nums[r];
                
                if(need == target){
                    solution.push_back({nums[l], nums[r], nums[i]});    
                    while(l<r && nums[l]==nums[l+1]){l++;}
                    while(l<r && nums[r]== nums[r-1]){ r--;}

                    l++;
                    r--;
                }
                else if(need > target){
                    r--;
                }
                else{
                    l++;
                }
            }


        }
        return solution;

    }

};
    