class Solution {
    struct Node {
        int child[26];
        bool end = false;

        Node() {
            fill(child, child + 26, -1);
        }
    };

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<Node> trie(1); // Index 0 is the root.

        // Insert all dictionary words into the trie.
        for (const string& word : wordDict) {
            int node = 0;

            for (char ch : word) {
                int index = ch - 'a';

                if (trie[node].child[index] == -1) {
                    int next = trie.size();
                    trie[node].child[index] = next;
                    trie.emplace_back();
                }

                node = trie[node].child[index];
            }

            trie[node].end = true;
        }

        int n = s.size();
        vector<bool> dp(n + 1, false);

        // An empty prefix is always valid.
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            // Start a new word only after a valid segmentation.
            if (!dp[i]) continue;

            int node = 0;

            for (int j = i; j < n; ++j) {
                int index = s[j] - 'a';

                // No dictionary word follows this character path.
                if (trie[node].child[index] == -1)
                    break;

                node = trie[node].child[index];

                // s[i..j] is a complete dictionary word.
                if (trie[node].end)
                    dp[j + 1] = true;
            }
        }

        return dp[n];
    }
};