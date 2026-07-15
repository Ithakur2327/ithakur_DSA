class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1)
            return 'a';

        long long len = 1;
        int oprs = -1;

        // Find the last operation that expanded length beyond k
        while(len < k) {
            len *= 2;
            oprs++;
        }

        // Recursively find the character in previous state
        char temp = kthCharacter(k - len/2, operations);

        // If last operation was type 1, increment character
        if(operations[oprs]==1){
            if(temp=='z')
                return 'a';
            else
                return temp+1;
        }

        return temp;
    }
};