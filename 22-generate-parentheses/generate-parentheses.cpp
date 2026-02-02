class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(vector<string>& res, string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            res.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(res, current + "(", open + 1, close, n);
        }
        
        if (close < open) {
            backtrack(res, current + ")", open, close + 1, n);
        }
    }
};