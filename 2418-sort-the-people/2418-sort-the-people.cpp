class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> map;
        for(int i= 0; i<heights.size(); i++){
            map[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end(), greater<int>());
        vector<string> result;
        for(int value : heights){
            result.push_back(map[value]);
        }
        return result;   
    }
};