class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            graph[u].push_back({v, w});
            graph[v].push_back({u, w * 2});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        vector<long long> dist(n, -1);
        
        pq.push({0, 0});
        
        while(!pq.empty()) {
            long long currentCost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(dist[node] != -1 && dist[node] < currentCost) {
                continue;
            }
            
            dist[node] = currentCost;
            
            if(node == n - 1) {
                return currentCost;
            }
            
            for(auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                if(dist[nextNode] == -1 || dist[nextNode] > currentCost + weight) {
                    dist[nextNode] = currentCost + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        return dist[n - 1] == -1 ? -1 : dist[n - 1];
    }
};