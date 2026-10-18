class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        vector<string> r(n);
        int i = 0, d = 1;
        for(int k = 0; k < s.size(); k++) {
            r[i].push_back(s[k]);
            if(i == 0) d = 1;
            if(i == n - 1) d = -1;
            i += d;
        }
        string a = "";
        for(int i = 0; i < n; i++)
            a += r[i];
        return a;
    }
};
