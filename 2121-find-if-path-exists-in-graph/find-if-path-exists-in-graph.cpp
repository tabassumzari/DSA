//using BFS

// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges,
//                    int source, int destination) {
//         vector<vector<int>> adj(n);

//         // Undirected graph: add each edge in both directions.
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }

//         vector<bool> visited(n, false);
//         queue<int> q;

//         q.push(source);
//         visited[source] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             if (node == destination)
//                 return true;

//             // Visit all unvisited neighbours.
//             for (int neighbour : adj[node]) {
//                 if (!visited[neighbour]) {
//                     // Mark before adding to avoid duplicate entries.
//                     visited[neighbour] = true;
//                     q.push(neighbour);
//                 }
//             }
//         }

//         return false;
//     }
// };

//DFS
//Uses an explicit stack to handle large graphs without deep recursion.

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {
        vector<vector<int>> adj(n);

        // Build the undirected adjacency list.
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        stack<int> st;

        st.push(source);
        visited[source] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (node == destination)
                return true;

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;

                    // A stack processes the latest added node first.
                    st.push(neighbour);
                }
            }
        }

        return false;
    }
};