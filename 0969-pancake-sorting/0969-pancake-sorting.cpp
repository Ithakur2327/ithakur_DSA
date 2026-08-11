class Solution {
public:
    vector<int> pancakeSort(vector<int>&arr) {
        vector<int>ans;

        for(int curr=arr.size()-1;curr>0;curr--){

            // Find maximum element in [0...curr]
            int maxIndex=0;

            for(int i=1;i<=curr;i++){
                if(arr[i]>arr[maxIndex]){
                    maxIndex=i;
                }
            }

            // Already in correct position
            if(maxIndex==curr){
                continue;
            }

            // Bring maximum element to the front
            if(maxIndex!=0){
                reverse(arr.begin(),arr.begin()+maxIndex+1);
                ans.push_back(maxIndex+1);
            }

            // Move maximum element to its correct position
            reverse(arr.begin(),arr.begin()+curr+1);
            ans.push_back(curr+1);
        }

        return ans;
    }
};