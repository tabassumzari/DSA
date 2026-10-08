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
    // Inorder traversal stores BST values in sorted order.
    void inorder(TreeNode* root, vector<int>& values) {
        if (!root) return;

        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;

        // Collect sorted values from both BSTs.
        inorder(root1, a);
        inorder(root2, b);

        int i = 0, j = 0;

        // Merge the two sorted arrays.
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j])
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        // Add remaining values from the first array.
        while (i < a.size())
            ans.push_back(a[i++]);

        // Add remaining values from the second array.
        while (j < b.size())
            ans.push_back(b[j++]);

        return ans;
    }
};