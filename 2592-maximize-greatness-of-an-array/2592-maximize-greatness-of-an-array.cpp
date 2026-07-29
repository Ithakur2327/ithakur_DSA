class Solution {
public:
    int maximizeGreatness(vector<int>& nums) { 
        sort(nums.begin(),nums.end());
        stack<int>st;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            st.push(nums[i]);
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<st.top()){
                cnt++;
                st.pop();
            }
        }
        return cnt;
    }
};