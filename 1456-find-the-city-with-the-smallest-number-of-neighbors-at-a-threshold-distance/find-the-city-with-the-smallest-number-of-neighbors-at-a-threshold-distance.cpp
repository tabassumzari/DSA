class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto& e : edges) {
            dist[e[0]][e[1]] = min(dist[e[0]][e[1]], e[2]);
            dist[e[1]][e[0]] = min(dist[e[1]][e[0]], e[2]);
        }

        // Try every city as an intermediate city.
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j],
                                    dist[i][k] + dist[k][j]);
                }
            }
        }

        int answer = -1, minCount = n;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // On a tie, choose the larger city number.
            if (count <= minCount) {
                minCount = count;
                answer = i;
            }
        }

        return answer;
    }
};