class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vals;

        for(auto &row : grid)
            for(int v : row)
                vals.push_back(v);
        int base = vals[0] % x;
        for(int v:vals){
            if(v%x!=base)
                return -1;
        }
            sort(vals.begin(), vals.end());
            int medium = vals[vals.size()/2];

            int ops = 0;
            for(int v : vals){
                ops += abs(v-medium) / x;
            }
            return ops;
        }        
    
};