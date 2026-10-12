struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
