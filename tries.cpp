#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool is_end;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        is_end = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->is_end = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return node->is_end;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.search("appl") << endl;
    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("ba") << endl;
    cout << trie.startsWith("cat") << endl;

    return 0;
}
