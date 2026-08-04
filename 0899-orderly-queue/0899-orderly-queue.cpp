class Solution {
public:
    string orderlyQueue(string s, int k){
        if(k>1){
         sort(s.begin(),s.end());
           return s;
 }
       string res=s;
       int n=s.length();
       for(int i=1;i<n;i++){
        string t =s.substr(i) + s.substr(0,i);
         res=min(res,t);
       }
       return res;
    }  
};