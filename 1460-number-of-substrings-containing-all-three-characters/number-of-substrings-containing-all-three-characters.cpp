class Solution {
public:
    int numberOfSubstrings(string s) {
        int total_count = 0;
        int last_seen[3] = {-1, -1, -1}; 

        for (int i = 0; i < s.length(); i++) {
            last_seen[s[i] - 'a'] = i; 

            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                int min_index = min({last_seen[0], last_seen[1], last_seen[2]});
                total_count += (min_index + 1);
            }
        }

        return total_count;
    }
};