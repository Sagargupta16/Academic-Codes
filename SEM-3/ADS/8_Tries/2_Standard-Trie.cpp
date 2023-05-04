#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    int count;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char d){
        data = d;
        count = 0;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string word){
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(temp->children[ch-'a'] == NULL){
                TrieNode* n = new TrieNode(ch);
                temp->children[ch-'a'] = n;
            }
            temp->children[ch-'a']->count++;
            temp = temp->children[ch-'a'];
        }
        temp->isTerminal = true;
    }
    void deleteWord(string word){
        deleteWordHelper(root,word);
    }
    bool deleteWordHelper(TrieNode* root, string word){
        if(word.length() == 0){
            if(root->isTerminal){
                root->isTerminal = false;
                return true;
            }
            else return false;
        }
        TrieNode* child = root->children[word[0]-'a'];
        if(child == NULL) return false;
        bool ans = deleteWordHelper(child,word.substr(1));
        if(!ans) return false;
        else{
            child->count--;
            if(child->count == 0){
                delete child;
                root->children[word[0]-'a'] = NULL;
            }
            return true;
        }
    }
    void print(){
        printHelper(root,"");
    }
    void printHelper(TrieNode* root, string word){
        if(root->isTerminal){
            cout<<word<<" ";
        }
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                printHelper(root->children[i],word+root->children[i]->data);
            }
        }
    }
    bool search(string word){
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(temp->children[ch-'a'] == NULL) return false;
            temp = temp->children[ch-'a'];
        }
        return temp->isTerminal;
    }
};

int main(){
    Trie t;
    t.insert("apple");
    t.insert("ape");
    t.insert("mango");
    t.insert("sagar");
    t.insert("sag");
    t.print();
    cout<<endl;
    t.search("sagar") ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    t.search("sag") ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    t.search("sagars") ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    t.deleteWord("sagar");
    t.print();
    cout<<endl;
    t.search("sagar") ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    return 0;
}