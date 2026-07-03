class Solution {
public:
    typedef long long ll;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);
        vector<int> costs;
        costs.reserve(edges.size());
        for (auto& e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            indeg[v]++;
            costs.push_back(c);
        }

        vector<int> topo;
        topo.reserve(n);
        vector<int> deg = indeg;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto& [v, c] : adj[u]) {
                if (--deg[v] == 0) q.push(v);
            }
        }

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        auto feasible = [&](int S) -> bool {
            vector<ll> dist(n, LLONG_MAX);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == LLONG_MAX) continue;
                if (u != 0 && !online[u]) continue;
                for (auto& [v, c] : adj[u]) {
                    if (c < S) continue;
                    ll nd = dist[u] + c;
                    if (nd < dist[v]) dist[v] = nd;
                }
            }
            return dist[n-1] != LLONG_MAX && dist[n-1] <= k;
        };

        int lo = 0, hi = (int)costs.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (feasible(costs[mid])) { ans = costs[mid]; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};