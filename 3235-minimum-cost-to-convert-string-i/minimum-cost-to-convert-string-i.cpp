class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> distMap(26, vector<long long>(26, -1));

        for(int i = 0; i < 26; i++) {
            distMap[i][i] = 0;
        }

        int m = original.size();
        for(int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            long long w = cost[i];

            if(distMap[u][v] == -1 || w < distMap[u][v]) {
                distMap[u][v] = w;
            }
        }

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(distMap[i][k] != -1 && distMap[k][j] != -1) {
                        long long newPath = distMap[i][k] + distMap[k][j];
                        if(distMap[i][j] == -1 || newPath < distMap[i][j]) {
                            distMap[i][j] = newPath;
                        }
                    }
                }
            }
        }

        long long finalBill = 0;
        int n = source.length();

        for(int i = 0; i < n; i++) {
            if(source[i] != target[i]) {
                int from = source[i] - 'a';
                int to = target[i] - 'a';

                if(distMap[from][to] == -1) {
                    return -1;
                }
                finalBill += distMap[from][to];
            }
        }

        return finalBill;
    }
};