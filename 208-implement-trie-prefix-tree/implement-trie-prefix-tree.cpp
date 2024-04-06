class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal = false;

    bool contains(char ch) { return children[ch - 'a'] != NULL; }
};

class Trie {
private:
TrieNode* root;

public:
    
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->contains(word[i])==NULL) {
                node->children[word[i] - 'a'] = new TrieNode();
            } 
                node = node->children[word[i] - 'a'];
            
        }
        node->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) {
                return false;
            } else {
                node = node->children[word[i] - 'a'];
            }
        }
        return node->isTerminal;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->contains(prefix[i])) {
                return false;
            } else {
                node = node->children[prefix[i] - 'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */