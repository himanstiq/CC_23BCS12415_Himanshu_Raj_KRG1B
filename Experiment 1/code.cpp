class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& f : flights)
            adj[f[0]].push_back({f[1], f[2]});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top(); pq.pop();
            if (node == dst) return cost;
            if (stops > k) continue;
            for (auto [next, w] : adj[node]) {
                if (cost + w < dist[next]) {
                    dist[next] = cost + w;
                    pq.push({cost + w, next, stops + 1});
                }
            }
        }
        return -1;
    }
};
