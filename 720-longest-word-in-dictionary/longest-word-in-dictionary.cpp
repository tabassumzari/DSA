class Solution {
    struct Node {
        int child[26];
        bool end = false;

        Node() {
            fill(child, child + 26, -1);
        }
    };

public:
    string longestWord(vector<string>& words) {
        vector<Node> trie(1);

        // Insert every word before checking prefixes.
        for (const string& word : words) {
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

        string answer;

        for (const string& word : words) {
            int node = 0;
            bool valid = true;

            for (char ch : word) {
                node = trie[node].child[ch - 'a'];

                // Each prefix must be a complete dictionary word.
                if (!trie[node].end) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                // Prefer longer words.
                // For equal lengths, prefer lexicographically smaller.
                if (word.size() > answer.size() ||
                    (word.size() == answer.size() && word < answer)) {
                    answer = word;
                }
            }
        }

        return answer;
    }
};