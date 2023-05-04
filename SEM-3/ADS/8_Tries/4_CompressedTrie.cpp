#include<iostream>
using namespace std;

class ComTrieNode{
    public:
        string s;
        int count;
        ComTrieNode** children;
        bool isTerminal;
        ComTrieNode(string s){
            this->s = s;
            count = 0;
            children = new ComTrieNode*[26];
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = true;
        }
};

class CompressedTrie{
    public:
        ComTrieNode* root;
        CompressedTrie(){
            root = new ComTrieNode("");
            root->isTerminal = false;
        }
        void insert(string word){
            insertHelper(root,word);
        }
        void insertHelper(ComTrieNode* root, string word){
            int i=0;
            while(i<root->s.length() && i<word.length() && word[i]==root->s[i]){
                i++;
            }
            if(i==word.length() && i==root->s.length()){
                root->isTerminal = true;
                return;
            }
            if(i==word.length()){
                ComTrieNode* n = new ComTrieNode(root->s.substr(i));
                for(int j=0;j<26;j++){
                    n->children[j] = root->children[j];
                    root->children[j] = NULL;
                }
                n->isTerminal = root->isTerminal;
                root->children[root->s[i]-'a'] = n;
                root->s = word;
                root->isTerminal = true;
                return;
            }
            if(i==root->s.length()){
                if(root->children[word[i]-'a'] == NULL){
                    root->children[word[i]-'a'] = new ComTrieNode(word.substr(i));
                }
                else{
                    insertHelper(root->children[word[i]-'a'],word.substr(i));
                }
                return;
            }
            if(i==0){
                root->children[word[i]-'a'] = new ComTrieNode(word);
            }
            
            string b=root->s.substr(i);
            string c=word.substr(i);
            root->s = root->s.substr(0, i);
            ComTrieNode* n = new ComTrieNode(b);
            for(int j=0;j<26;j++){
                n->children[j] = root->children[j];
                root->children[j] = NULL;
            }
            n->isTerminal = root->isTerminal;
            root->isTerminal = false;
            root->children[b[0] - 'a'] = n;
            root->children[c[0]-'a'] = new ComTrieNode(c);
        }
        
        void print(){
            printHelper(root,"");
        }
        void printHelper(ComTrieNode* root, string s){
            if(root->isTerminal){
                cout<<s<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i] != NULL){
                    printHelper(root->children[i],s+root->children[i]->s);
                }
            }
        }
        bool search(string word){
            return searchHelper(root,word);
        }
        bool searchHelper(ComTrieNode* root, string word){
            if(word.length() == 0){
                if(root->isTerminal){
                    return true;
                }
                else{
                    return false;
                }
            }
            int i=0;
            while(i<root->s.length() && i<word.length() && word[i]==root->s[i]){
                i++;
            }
            if(i==word.length() && i==root->s.length()){
                return root->isTerminal;
            }
            if(root->children[word[i]-'a'] == NULL){
                return false;
            }
            return searchHelper(root->children[word[i]-'a'],word.substr(i));
        }
};

int main(){
    CompressedTrie t;
    t.insert("abc");
    t.insert("abcd");
    t.insert("ab");
    t.insert("sagar");
    t.insert("sabo");
    t.insert("sachin");
    t.print();
    cout<<endl;
    cout<<t.search("cd")<<endl;
    cout<<t.search("abcd")<<endl;
}