#include <vector>
#include <string>
using namespace std;
class Trie {
public:
    struct TrieNode {
        int pass;
        int end;
        vector<TrieNode*> nodes;
        TrieNode(int pass = 0, int end = 0) 
         : pass(pass) , end(end), nodes(26, nullptr) {}
    };
private:
    TrieNode* root;
    int Index(char c) {
        return c - 'a';
    }
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode *cur = root;
        for(char c : word) {
            int idx = Index()
        }
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */