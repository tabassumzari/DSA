/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    // Store values in preorder: Root -> Left -> Right.
    void preorder(TreeNode* root, string& data) {
        if (!root) return;

        data += to_string(root->val) + " ";
        preorder(root->left, data);
        preorder(root->right, data);
    }

    TreeNode* build(vector<int>& values, int& i,
                    long long low, long long high) {
        // All values have been used.
        if (i == values.size()) return nullptr;

        int value = values[i];

        // Leave this value for another subtree if outside the range.
        if (value <= low || value >= high)
            return nullptr;

        // Consume the value and create a node.
        ++i;
        TreeNode* root = new TreeNode(value);

        // Left values must be smaller; right values must be greater.
        root->left = build(values, i, low, value);
        root->right = build(values, i, value, high);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        preorder(root, data);
        return data;
    }

    // Decodes your encoded data to a tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> values;
        int value;

        // Read the space-separated values.
        while (ss >> value)
            values.push_back(value);

        // Track the next unused preorder value.
        int i = 0;
        return build(values, i, LLONG_MIN, LLONG_MAX);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;