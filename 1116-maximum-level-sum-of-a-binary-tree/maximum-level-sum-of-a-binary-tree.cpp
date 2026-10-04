/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        // Queue is used for Level Order Traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // Current level number
        int level = 1;

        // Stores the level having maximum sum
        int ansLevel = 1;

        // Initialize maximum sum to the smallest possible integer
        int maxSum = INT_MIN;

        while (!q.empty()) {
            
            // Number of nodes present at the current level
            int size = q.size();

            // Sum of nodes at the current level
            int sum = 0;

            // Process all nodes of the current level
            for (int i = 0; i < size; i++) {
                
                // Get the front node
                TreeNode* node = q.front();
                q.pop();

                // Add node value to current level's sum
                sum += node->val;

                // Add left child to queue
                if (node->left)
                    q.push(node->left);

                // Add right child to queue
                if (node->right)
                    q.push(node->right);
            }

            // If current level has a greater sum,
            // update maximum sum and answer level
            if (sum > maxSum) {
                maxSum = sum;
                ansLevel = level;
            }

            // Move to the next level
            level++;
        }

        // Return the level with maximum sum
        return ansLevel;
    }
};