class Solution {
public:
    vector<string> ans;

    void solve(int open, int close, string cur) {
        if (open == 0 && close == 0) {
            ans.push_back(cur);
            return;
        }

        if (open > 0)
            solve(open - 1, close, cur + '(');

        if (close > open)
            solve(open, close - 1, cur + ')');
    }

    vector<string> generateParenthesis(int n) {
        solve(n, n, "");
        return ans;
    }
};