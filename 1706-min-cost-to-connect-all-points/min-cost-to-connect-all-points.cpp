class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);

        dist[0] = 0;
        int cost = 0;

        for (int count = 0; count < n; count++) {
            int u = -1;

            // Select the nearest unvisited point.
            for (int i = 0; i < n; i++) {
                if (!vis[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }

            vis[u] = true;
            cost += dist[u];

            // Update connection costs.
            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int weight = abs(points[u][0] - points[v][0])
                               + abs(points[u][1] - points[v][1]);

                    dist[v] = min(dist[v], weight);
                }
            }
        }

        return cost;
    }
};