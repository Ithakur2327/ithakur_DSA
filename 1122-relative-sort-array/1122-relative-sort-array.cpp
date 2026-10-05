class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector <int> ans;
        map <int, int> freq;
        for (int i = 0; i < arr1.size(); i++) 
            freq[arr1[i]]++;  

        for (int i = 0; i < arr2.size(); i++)
        {
            int num = arr2[i];
            auto pair = freq.find(num);
            for (int j = 0; j < pair->second; j++) ans.push_back(num);
            freq.erase(pair);
        }

        for (auto& p : freq)
        {
            for (int j = 0; j < p.second; j++) ans.push_back(p.first);
        }

        return ans;
    }
};