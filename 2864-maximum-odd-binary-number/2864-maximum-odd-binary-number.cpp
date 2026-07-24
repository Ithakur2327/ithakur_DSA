class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), i = 0;
        for (int j=0; j<n; j++)
        if (s[j] == '1') swap(s[i], s[j]), i++;
        swap(s[i - 1], s[n - 1]); 
        return s;
    }
};