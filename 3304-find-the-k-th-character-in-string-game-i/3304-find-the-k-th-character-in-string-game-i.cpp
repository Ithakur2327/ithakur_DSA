class Solution {
public:
    char kthCharacter(int k) {
         if(k==0) return 'a';
           return 'a'+__builtin_popcount(k-1);
    }
};