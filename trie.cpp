#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool end = false;

    void put(Node* node ,char ch) {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie{
    Node* root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(string s) {
            int size = s.size();
            Node* node = root;

            for(int i=0 ;i<size ;i++) {
                if(!node -> containsKey(s[i])) {
                    node -> put(new Node() ,s[i]);
                }
                node = node -> get(s[i]);
            }
            node -> end = true;
        }

        bool search(string s) {
            int size = s.size();
            Node* node = root;

            for(int i=0 ;i<size ;i++) {
                char ch = s[i];
                if(!node -> containsKey(ch)) return false;
                node = node -> get(ch);
            }
            return (node -> end ? true : false);
        }

        bool startsWith(string prefix) {
            Node* node = root;
            for (char ch : prefix) {
                if (!node->containsKey(ch)) return false;
                node = node->get(ch);
            }
            return true;
        }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha;
    cout << "search('apple'): " << trie.search("apple") << endl;  // true
    cout << "search('app'): " << trie.search("app") << endl;      // true
    cout << "search('appl'): " << trie.search("appl") << endl;    // false
    cout << "startsWith('ap'): " << trie.startsWith("ap") << endl; // true
    cout << "startsWith('bat'): " << trie.startsWith("bat") << endl; // true
    cout << "startsWith('bad'): " << trie.startsWith("bad") << endl; // false

    return 0;
}
