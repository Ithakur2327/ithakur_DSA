class Solution {
public:
    unordered_map<string , bool> mp;
    bool checkConcatenate(string word,set<string>&s) {
        if(mp.find(word) != mp.end()){
            return mp[word];
        }
        for(int i = 1; i < word.length(); i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            if(s.find(prefix) != s.end() && (s.find(suffix) != s.end() || checkConcatenate(suffix,s)))
                return mp[word]=true;
        }
        return mp[word]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        mp.clear();
        set<string> s(words.begin(),words.end());
        for(string word : words) {
            s.erase(word);
            if(checkConcatenate(word,s) == true)
                res.push_back(word);
                 s.insert(word);
        }
        return res;
    }
};