class Solution {
public:
bool is_vowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    string reverseWords(string s) {
        int n = s.size();
        int i=0;

        int cnt_vow = 0;

        while(i<n && s[i]!=' ')
        {
            if(is_vowel(s[i]))cnt_vow++;
            i++;
        }

        while(i<n)
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }

            int fidx = i;
            int vow = 0;

            while(i<n && s[i]!=' ')
            {
                if(is_vowel(s[i]))vow++;
                i++;
            }

            int lidx = i-1;

            if(vow == cnt_vow)
            {
                int l=fidx, r=lidx;
                while(l<r)
                {
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }
            }
        }

        return s;
    }
};