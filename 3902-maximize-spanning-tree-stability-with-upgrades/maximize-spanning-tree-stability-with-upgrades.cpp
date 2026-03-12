class Solution {
public:
struct DisjointSet {
        vector<int> parent;
        vector<int> rankValue;

        DisjointSet(int n) {
            parent.resize(n);
            rankValue.assign(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }

        int findParent(int node) {
            if (parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        bool unite(int firstNode, int secondNode) {
            int firstParent = findParent(firstNode);
            int secondParent = findParent(secondNode);

            if (firstParent == secondParent) return false;

            if (rankValue[firstParent] < rankValue[secondParent]) {
                swap(firstParent, secondParent);
            }

            parent[secondParent] = firstParent;
            if (rankValue[firstParent] == rankValue[secondParent]) {
                rankValue[firstParent]++;
            }

            return true;
        }
    };

    bool canBuildStableTree(int n, vector<vector<int>>& edges, int k, int targetStability) {
        DisjointSet dsu(n);
        int edgesUsed = 0;
        int upgradesUsed = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 1) {
                if (strength < targetStability) return false;
                if (!dsu.unite(u, v)) return false;
                edgesUsed++;
            }
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 0 && strength >= targetStability) {
                if (dsu.unite(u, v)) {
                    edgesUsed++;
                }
            }
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 0 && strength < targetStability && 2LL * strength >= targetStability) {
                if (dsu.unite(u, v)) {
                    edgesUsed++;
                    upgradesUsed++;
                    if (upgradesUsed > k) return false;
                }
            }
        }

        return edgesUsed == n - 1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int highestPossibleStability = 0;

        for (auto& edge : edges) {
            int strength = edge[2];
            int mustInclude = edge[3];

            if (mustInclude == 1) {
                highestPossibleStability = max(highestPossibleStability, strength);
            } else {
                highestPossibleStability = max(highestPossibleStability, 2 * strength);
            }
        }

        if (!canBuildStableTree(n, edges, k, 1)) {
            return -1;
        }

        int left = 1;
        int right = highestPossibleStability;
        int bestAnswer = 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (canBuildStableTree(n, edges, k, middle)) {
                bestAnswer = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return bestAnswer;
    }
};