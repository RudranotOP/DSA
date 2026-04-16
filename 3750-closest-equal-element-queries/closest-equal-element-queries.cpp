class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        vector<int> best(n, -1);
        
        for (auto& [val, v] : pos) {
            int m = v.size();
            if (m == 1) continue;
            
            for (int i = 0; i < m; i++) {
                int cur = v[i];
                int prv = v[(i - 1 + m) % m];
                int nxt = v[(i + 1) % m];
                
                int d1 = abs(cur - prv);
                d1 = min(d1, n - d1);
                
                int d2 = abs(cur - nxt);
                d2 = min(d2, n - d2);
                
                best[cur] = min(d1, d2);
            }
        }
        
        vector<int> ans;
        for (int idx : queries) ans.push_back(best[idx]);
        return ans;
    }
};