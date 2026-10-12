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

class WordDictionary {
public:
    TrieNode* root;

    bool searchDFS(string word, int index, TrieNode* node) {
        if (index == word.length()) {
            return node->isEndOfWord;
        }

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (searchDFS(word, index + 1, node->children[i])) return true;
                }
            }
            return false;
        } else {
            int childIndex = c - 'a';
            if (node->children[childIndex] == nullptr) {
                return false;
            }
            return searchDFS(word, index + 1, node->children[childIndex]);
        }
    }

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchDFS(word, 0, root);
    }
};
