class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // {node, {cost, stops}}
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({src, {0, -1}});

        while (!q.empty()) {
            auto val = q.front();
            q.pop();

            int u = val.first;
            int cost = val.second.first;
            int stops = val.second.second;

            if (stops == k) continue;

            for (auto& edge : graph[u]) {
                int v = edge.first;
                int wt = edge.second;

                if (cost + wt < dist[v]) {
                    dist[v] = cost + wt;
                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];

        
        //return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};