/*
    Author  :   RooT NovA
    PS      :   Return Longest Common Prefix of given strings
    Method  :   Tries
    Example :   1
                3
                apple ape april
    Output  :   app
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Trie {
    struct TrieNode {
        bool isLeaf;
        TrieNode* child[26];
        char data;
    };
    TrieNode* root;
    
    TrieNode* getNode(int index) {
        TrieNode* temp = new TrieNode();
        temp->data = index + 'a';
        temp->isLeaf = false;
        for(int i = 0; i < 26; i++)
            temp->child[i] = NULL;
        return temp;
    }
    public : 
        Trie() {
            root = getNode('/' - 'a');
        }
        void insert(string word) {
            TrieNode* curr = root;
            int index;
            for(int i = 0; i < word.size(); i++) {
                index = word[i] - 'a';
                if(curr->child[index] == NULL)
                    curr->child[index] = getNode(index);
                curr = curr->child[index];
            }
            curr->isLeaf = true;
        }
        
        int countChildren(TrieNode* node, int* index) {
            int count = 0;
            for(int i = 0; i < 26; i++) {
                if(node->child[i] != NULL) {
                    count++;
                    *index = i;
                }
            }
            return count;
        }
        
        string walkTrie() {
            TrieNode* pCrawl = root;
            int index;
            string prefix;
            while( (countChildren(pCrawl, &index) == 1) && (pCrawl->isLeaf == false) ) {
                pCrawl = pCrawl->child[index];
                prefix += 'a' + index;
            }
            return prefix;
        }      
};

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        Trie* t = new Trie();
        int n;
        cin>>n;
        for(int i = 0; i < n; i++) {
            string s;
            cin>>s;
            t->insert(s);
        }
        string res = t->walkTrie();
        if(res == "")
            cout<<-1<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}