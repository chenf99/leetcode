/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>
using std::string;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TreeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) node->children[index] = new TreeNode();
            node = node->children[index];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* node = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return true;
    }
private:
    struct TreeNode {
        bool end;
        TreeNode* children[26] = {nullptr};
        TreeNode() {
            end = false;
        }
    };
    TreeNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

