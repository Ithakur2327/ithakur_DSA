class Solution{
public:
    int solve(int i,vector<string>& words,vector<int>& freq,vector<int>& score){
        if(i==words.size())return 0;

        int notTake=solve(i+1,words,freq,score);

        string word=words[i];
        vector<int> temp=freq;
        int takeScore=0;
        bool ok=1;

        for(char c:word){
            temp[c-'a']--;
            if(temp[c-'a']<0){
                ok=0;
                break;
            }
            takeScore+=score[c-'a'];
        }

        int take=0;
        if(ok){
            take=takeScore+solve(i+1,words,temp,score);
        }

        return max(take,notTake);
    }

    int maxScoreWords(vector<string>& words,vector<char>& letters,vector<int>& score){
        vector<int> freq(26,0);

        for(char c:letters){
            freq[c-'a']++;
        }
        
        return solve(0,words,freq,score);
    }
};