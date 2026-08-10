class Solution {
public:
    int longestDecomposition(string text) {
        int n=text.size();

        int left=0;
        int right=n-1;

        string a="";
        string b="";

        int ans=0;

        while(left<=right){
            a+=text[left];
            b=text[right]+b;

            if(a==b){
                if(left==right){
                    ans++;
                }
                else{
                    ans+=2;
                }

                a="";
                b="";
            }

            left++;
            right--;
        }

        if(!a.empty()){
            ans++;
        }

        return ans;
    }
};