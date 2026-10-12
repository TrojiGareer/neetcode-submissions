struct TrieNode {
        TrieNode* children[26];
        string word; 

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

class Solution {
public:
    TrieNode* root;
    vector<string> result;
    int rows, cols;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        // Verificăm limitele matricii și dacă celula a fost deja vizitată
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        int index = ch - 'a';

        // Dacă nu există ramura în Trie, tăiem execuția (pruning)
        if (node->children[index] == nullptr) {
            return;
        }

        // Ne mutăm pe nodul următor în Trie
        TrieNode* nextNode = node->children[index];

        // Am găsit un cuvânt valid?
        if (nextNode->word != "") {
            result.push_back(nextNode->word);
            nextNode->word = ""; // Golim ca să evităm adăugarea duplicatelor
        }

        // Marcăm celula ca vizitată
        board[r][c] = '#';

        // Explorăm cele 4 direcții: Jos, Sus, Dreapta, Stânga
        dfs(board, r + 1, c, nextNode);
        dfs(board, r - 1, c, nextNode);
        dfs(board, r, c + 1, nextNode);
        dfs(board, r, c - 1, nextNode);

        // Backtracking: restaurăm litera originală
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        rows = board.size();
        cols = board[0].size();

        // 1. Construim Trie-ul
        for (const string& word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            // Salvăm cuvântul complet la final
            curr->word = word; 
        }

        // 2. Parcurgem matricea și lansăm DFS din fiecare celulă
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return result;
    }
};
