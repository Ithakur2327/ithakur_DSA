class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=1;i<=s.size();i++){
            int diff=123-s[i-1];
            sum +=diff*i;
        }
        return sum;
        
    }
};