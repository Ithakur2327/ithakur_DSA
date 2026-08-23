class Solution{
public:
    bool solve(string& s,int& i){
        char c=s[i];

        if(c=='t'){
            i++;
            return true;
        }

        if(c=='f'){
            i++;
            return false;
        }

        i+=2;

        if(c=='!'){
            bool ans=solve(s,i);
            i++;
            return !ans;
        }

        bool ans=(c=='&');

        while(s[i]!=')'){
            if(s[i]==','){
                i++;
                continue;
            }

            bool val=solve(s,i);

            if(c=='&')
                ans=ans&&val;
            else
                ans=ans||val;
        }

        i++;

        return ans;
    }

    bool parseBoolExpr(string expression){
        int i=0;
        return solve(expression,i);
    }
};
