class Trie {
    struct Node {
        int child[26];
        bool end = false;

        Node() {
            fill(child, child + 26, -1);
        }
    };

    vector<Node> nodes;

    // Return the node reached by following the text.
    // Return -1 if its path does not exist.
    int findNode(const string& text) {
        int node = 0;

        for (char ch : text) {
            int index = ch - 'a';

            if (nodes[node].child[index] == -1)
                return -1;

            node = nodes[node].child[index];
        }

        return node;
    }

public:
    Trie() {
        nodes.emplace_back(); // Create the root.
    }

    void insert(string word) {
        int node = 0;

        for (char ch : word) {
            int index = ch - 'a';

            // Create a node if this character path is missing.
            if (nodes[node].child[index] == -1) {
                int next = nodes.size();
                nodes[node].child[index] = next;
                nodes.emplace_back();
            }

            node = nodes[node].child[index];
        }

        // Mark the end of a complete word.
        nodes[node].end = true;
    }

    bool search(string word) {
        int node = findNode(word);

        // The path must exist and end at a complete word.
        return node != -1 && nodes[node].end;
    }

    bool startsWith(string prefix) {
        // A prefix only requires an existing path.
        return findNode(prefix) != -1;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */