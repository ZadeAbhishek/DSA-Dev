#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
 public:
  TrieNode* root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
    // We have to add all suffix in the Trie 
    for (int i = 0; i < str.size(); i++) {
      TrieNode* currNode = root;
      for (int j = i; j < str.size(); j++) {
        char chr = str[j];
        if (!currNode->children.count(chr)) {
          currNode->children[chr] = new TrieNode();
        }
        currNode = currNode->children[chr];
      }
      currNode->children[endSymbol] = nullptr;  // Mark the end of a suffix
    }
  }

  bool contains(string str) {
    TrieNode* currNode = root;
    for (char chr : str) {
      if (!currNode->children.count(chr)) {
        return false;
      }
      currNode = currNode->children[chr];
    }
    return currNode->children.count(endSymbol);  // Ensure it's a complete suffix
  }
};