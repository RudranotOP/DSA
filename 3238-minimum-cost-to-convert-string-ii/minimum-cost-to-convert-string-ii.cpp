class Solution {
    struct TrieNode {
        TrieNode* children[26];
        int id;
        TrieNode() {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
            id = -1;
        }
    };

    void insert(TrieNode* root, string& s, int id) {
        TrieNode* curr = root;
        for(char c : s) {
            int idx = c - 'a';
            if(!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->id = id;
    }
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> stringToId;
        int idCounter = 0;

        for(auto& s : original) {
            if(stringToId.find(s) == stringToId.end()) stringToId[s] = idCounter++;
        }
        for(auto& s : changed) {
            if(stringToId.find(s) == stringToId.end()) stringToId[s] = idCounter++;
        }

        int numNodes = idCounter;
        long long INF = 1e15;
        vector<vector<long long>> dist(numNodes, vector<long long>(numNodes, INF));

        for(int i = 0; i < numNodes; i++) dist[i][i] = 0;

        for(size_t i = 0; i < cost.size(); i++) {
            int u = stringToId[original[i]];
            int v = stringToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for(int k = 0; k < numNodes; k++) {
            for(int i = 0; i < numNodes; i++) {
                for(int j = 0; j < numNodes; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        TrieNode* root = new TrieNode();
        for(auto& pair : stringToId) {
            string s = pair.first;
            insert(root, s, pair.second);
        }

        int n = source.length();
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(source[i] == target[i]) {
                dp[i] = min(dp[i], dp[i+1]);
            }

            TrieNode* curr = root;
            for(int len = 0; i + len < n; len++) {
                int charIdx = source[i + len] - 'a';
                if(!curr->children[charIdx]) break;
                
                curr = curr->children[charIdx];
                
                if(curr->id != -1) {
                    int u = curr->id;
                    string targetSub = target.substr(i, len + 1);
                    if(stringToId.count(targetSub)) {
                        int v = stringToId[targetSub];
                        if(dist[u][v] < INF && dp[i + len + 1] < INF) {
                            dp[i] = min(dp[i], dist[u][v] + dp[i + len + 1]);
                        }
                    }
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};