//Undirected Cycle using BFS
//Before adding an edge u—v, check whether a path already connects them. If it does, adding the edge creates a cycle.

class Solution {
    bool hasPath(int source, int destination,
                 vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            // An existing path plus this edge forms a cycle.
            if (hasPath(u, v, adj))
                return edge;

            // Otherwise, safely add the edge.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};

//Undirected Cycle using DFS

// class Solution {
//     bool hasPath(int node, int destination,
//                  vector<vector<int>>& adj,
//                  vector<bool>& visited) {
//         if (node == destination)
//             return true;

//         visited[node] = true;

//         // Explore each unvisited neighbour recursively.
//         for (int neighbour : adj[node]) {
//             if (!visited[neighbour] &&
//                 hasPath(neighbour, destination, adj, visited)) {
//                 return true;
//             }
//         }

//         return false;
//     }

// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<vector<int>> adj(n + 1);

//         for (auto& edge : edges) {
//             int u = edge[0], v = edge[1];
//             vector<bool> visited(n + 1, false);

//             // Check connectivity before inserting the new edge.
//             if (hasPath(u, v, adj, visited))
//                 return edge;

//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         return {};
//     }
// };