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
    int ans = 0;

    int height(TreeNode* root) {//O(n)
        if (root == NULL){
            return 0;
        }
        int leftHit = height(root->left);
        int rightHit = height(root->right);
        
        ans = max(ans, leftHit + rightHit); //currDiam of root node
        return max(leftHit, rightHit) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return ans;
    }
};