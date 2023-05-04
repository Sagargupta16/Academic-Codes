#include<iostream>
using namespace std;

class Node{
    public:
    string s;
    int count;
    Node** child;
    bool isT;
    Node(string st){
        s=st;
        count=0;
        child = new Node*[26];
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isT=true;
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node("");
            root->isT=false;
        }
        void insert(string word){
            insertHelper(root,word);
        }
        void insertHelper(Node* root,string word){
            if(root->child[word[0]-'a']==NULL){
                root->child[word[0]-'a'] = new Node(word);
                return;
            }
            int i=0;
            while(root->s[i]==word[i]){
                i++;
            }
        }
};