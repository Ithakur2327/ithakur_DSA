class Solution {
public:
    int minSwaps(string s) {
        int balance=0;

        for(char ch:s){
            if(ch=='['){
                balance++;
            }
            else if(balance>0){
                balance--;
            }
        }

        return (balance+1)/2;
    }
};