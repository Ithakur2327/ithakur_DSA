class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
     unordered_map<int,int>maaap;
     sort(nums.begin(),nums.end());
     int rtrn = -1;
     for(auto n : nums)
     {   
        int root = sqrt(n);
        if(root*root==n && maaap.find(root)!=maaap.end())
        {
            maaap[n]=maaap[root]+1;
            rtrn = max(rtrn , maaap[n]);
        }
        else  maaap[n]=1;
     }   
     return rtrn;
    }
};