class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob=0;
        int i=0;
        int n=colors.size();

        while(i<n){
            int j=i;

            while(j<n&&colors[j]==colors[i]){
                j++;
            }

            int len=j-i;

            if(len>=3){
                if(colors[i]=='A'){
                    alice+=len-2;
                }
                else{
                    bob+=len-2;
                }
            }

            i=j;
        }

        return alice>bob;
    }
};