class Solution{
public:
    int countCharacters(vector<string>& words,string chars){
        int sum=0;
        for(auto word:words){
            vector<int> freq(26,0);
            for(char c:chars){
                freq[c-'a']++;
            }
            bool valid=true;
            for(char c:word){
                freq[c-'a']--;
                if(freq[c-'a']<0){
                    valid=false;
                    break;
                }
            }
            if(valid){
                sum+=word.length();
            }
        }
        return sum;
    }
};