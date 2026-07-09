class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        int c = 0, m = 0;
        for(int i=0;i<n;i++){
            ans[i] += m;
            if(boxes[i] == '1') c++;
            m += c;
        }
        c=0,m=0;
        for(int i = n-1;i>=0;i--){
            ans[i] += m;
            if(boxes[i] == '1') c++;
            m += c;
        }
        return ans;
    }
};