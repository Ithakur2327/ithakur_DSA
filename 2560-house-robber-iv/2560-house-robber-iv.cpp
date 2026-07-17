class Solution {
public:
    bool check(vector<int>& nums,int k,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }

    int minCapability(vector<int>& nums,int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());

        while(l<r){
            int mid=l+(r-l)/2;
            if(check(nums,k,mid))
                r=mid;
            else
                l=mid+1;
        }

        return l;
    }
};