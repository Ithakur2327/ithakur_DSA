class Solution {
public:
    int trailingZeroes(int n) {
        int yoo=0;
        while(n>0){
            n /=5;
            yoo +=n;
        }return yoo;
    }
};