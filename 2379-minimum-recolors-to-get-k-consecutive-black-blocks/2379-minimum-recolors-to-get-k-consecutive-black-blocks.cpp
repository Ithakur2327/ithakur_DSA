class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0, ans = k;
    for(int i = 0; i < blocks.size(); ++i){
        if(blocks[i] == 'W') count++;
        if(i >= k && blocks[i - k] == 'W') count--;
        if(i+1 >= k) ans = min(ans, count);
    }
      return min(ans, count);
    }
};