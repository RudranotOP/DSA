class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(int val : nums) {
            if(seen.count(val)) {
                return val;
            }
            seen.insert(val);
        }
        
        return -1;
    }
};