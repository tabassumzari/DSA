//Directed Cycle using DFS

// class Solution {
//     bool hasCycle(int node, vector<vector<int>>& adj,
//                   vector<int>& state) {
//         // 0 = unvisited, 1 = currently exploring, 2 = finished.
//         state[node] = 1;

//         for (int neighbour : adj[node]) {
//             // Reaching a node on the current DFS path forms a cycle.
//             if (state[neighbour] == 1)
//                 return true;

//             if (state[neighbour] == 0 &&
//                 hasCycle(neighbour, adj, state)) {
//                 return true;
//             }
//         }

//         // This node and all its outgoing paths are processed.
//         state[node] = 2;
//         return false;
//     }

// public:
//     bool canFinish(int numCourses,
//                    vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);

//         // [a, b] means b must be completed before a: b -> a.
//         for (auto& p : prerequisites)
//             adj[p[1]].push_back(p[0]);

//         vector<int> state(numCourses, 0);

//         // Check every component of the graph.
//         for (int i = 0; i < numCourses; ++i) {
//             if (state[i] == 0 && hasCycle(i, adj, state))
//                 return false;
//         }

//         return true;
//     }
// };


//Directed Cycle using BFS
//Kahn’s algorithm repeatedly removes nodes with zero indegree.

class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            // Prerequisite course -> dependent course.
            adj[p[1]].push_back(p[0]);

            // Count incoming prerequisite edges.
            indegree[p[0]]++;
        }

        queue<int> q;

        // These courses have no unfinished prerequisites.
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
         int completed = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completed++;

            for (int next : adj[course]) {
                // This prerequisite has now been completed.
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // A cycle prevents some courses from reaching zero indegree.
        return completed == numCourses;
    }
};