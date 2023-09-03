#include <iostream>
using namespace std;

// Define a Trie class
class Trie {
private:
    Trie* child[26] = {}; // An array of pointers for each character ('a' to 'z')
    bool isWord = false; // Indicates if this node represents a complete word

    // Recursive function to insert a word into the Trie
    void insert2(string word, Trie* prev) {
        // If the word is empty, mark the current node as a complete word
        if (word.size() == 0) {
            prev->isWord = true;
            return;
        }

        Trie* curr = prev; // Current Trie node
        int idx = word[0] - 'a'; // Calculate the index for the first character
        if (curr->child[idx] == nullptr) curr->child[idx] = new Trie(); // If the child doesn't exist, create a new Trie node
        insert2(word.substr(1), curr->child[idx]); // Recursively insert the rest of the word
    }

    // Iterative function to insert a word into the Trie
    void insertChar(string word) {
        Trie* current = this; // Current Trie node
        for (auto ch : word) {
            int idx = ch - 'a'; // Calculate the index for the character
            if (current->child[idx] == nullptr)
                current->child[idx] = new Trie(); // If the child doesn't exist, create a new Trie node
            current = current->child[idx]; // Move to the next Trie node
        }
        current->isWord = true; // Mark the last node as a complete word
    }

public:
    // Public function to insert a word into the Trie
    void insert(string s) {
        // insertChar(s); // You can choose between recursive or iterative insert
        insert2(s, this); // This uses the recursive insert
    }

    // Public function to search for a complete word in the Trie
    bool searchWord(string word) {
        Trie* current = this; // Start at the root of the Trie
        for (auto ch : word) {
            int idx = ch - 'a'; // Calculate the index for the character
            if (current->child[idx] == nullptr)
                return false; // If the child doesn't exist, the word is not in the Trie
            current = current->child[idx]; // Move to the next Trie node
        }
        return current->isWord; // Check if the last node represents a complete word
    }

    // Public function to check if a prefix exists in the Trie
    bool prefixCheck(string word) {
        Trie* current = this; // Start at the root of the Trie
        for (auto ch : word) {
            int idx = ch - 'a'; // Calculate the index for the character
            if (current->child[idx] == nullptr)
                return false; // If the child doesn't exist, the prefix is not in the Trie
            current = current->child[idx]; // Move to the next Trie node
        }
        return true; // The prefix is found in the Trie
    }
};

int main() {
    Trie* t = new Trie(); // Create a new Trie instance
    t->insert("abhishek"); // Insert a word into the Trie
    cout << t->searchWord("abhi") << endl; // Search for a complete word
    cout << t->prefixCheck("ab") << endl; // Check if a prefix exists
    cout << t->prefixCheck("abhi") << endl; // Check if a prefix exists
    cout << t->prefixCheck("abhishek") << endl; // Check if a prefix exists

    return 0;
}
