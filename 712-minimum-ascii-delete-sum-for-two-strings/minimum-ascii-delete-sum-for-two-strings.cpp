class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int firstLen = s1.length();
        int secondLen = s2.length();
        
        vector<vector<int>> grid(firstLen + 1, vector<int>(secondLen + 1, 0));
        
        int totalWeight = 0;
        for (char c : s1) totalWeight += (int)c;
        for (char c : s2) totalWeight += (int)c;

        for (int i = 1; i <= firstLen; i++) {
            for (int j = 1; j <= secondLen; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    grid[i][j] = grid[i - 1][j - 1] + (int)s1[i - 1];
                } else {
                    grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        int commonWeight = grid[firstLen][secondLen];
        return totalWeight - (2 * commonWeight);
    }
};