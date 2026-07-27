class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>&arr,int k) {
        unordered_map<int,int>freq;

        for(int num:arr){
            freq[num]++;
        }

        vector<int>count;
        for(auto &it:freq){
            count.push_back(it.second);
        }
        sort(count.begin(),count.end());

        int unique=count.size();

        for(int f:count){
            if(k<f){
                break;
            }
            k-=f;
            unique--;
        }
        return unique;
    }
};