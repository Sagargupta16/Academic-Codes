#include<iostream>
using namespace std;

class Node{
    public:
    int count;
    Node** child;
    bool isT;
    Node(){
        count=0;
        isT=false;
        child = new Node*[26];
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        for(int i=0;i<word.length();i++){
            insertHelper(root,word.substr(i));
        }
    }
    void insertHelper(Node* root,string word){
        if(word==""){
            root->isT=true;
            return;
        }
        root->count++;
        if(root->child[word[0]-'a']==NULL){
            Node *x = new Node();
            root->child[word[0]-'a']=x;
        }
        insertHelper(root->child[word[0]-'a'],word.substr(1));
    }
    bool search(string word){
        return searchHelper(root,word);
    }
    bool searchHelper(Node* root,string word){
        if(word=="" && root->isT) return true;
        if(word=="" || root->child[word[0]-'a']==NULL) return false;
        return searchHelper(root->child[word[0]-'a'],word.substr(1));
    }
    void Delete(string word){
        if(!search(word)) return;
        for(int i=0;i<word.length();i++){
            DeleteHelper(root,word.substr(i));
        }
    }
    void DeleteHelper(Node* root,string word){
        if(word==""){
            root->isT=false;
            return;
        }
        root->count--;
        Node* x = root->child[word[0]-'a'];
        if(root->child[word[0]-'a']->count==1){
            root->child[word[0]-'a']=NULL;
        }
        if(root->count==0) delete root;
        DeleteHelper(x,word.substr(1));
    }
    void print(){
        cout<<endl;
        printHelper(root,"");
        cout<<endl;
    }
    void printHelper(Node* root,string word){
        if(root->isT) cout<<word<<endl;
        for(int i=0;i<26;i++){
            if(root->child[i]!=NULL){
                string s = word;
                s+=(i+'a');
                printHelper(root->child[i],s);
            }
        }
    }
};
int main(){
    Trie t;
    t.insert("sagar");
    t.insert("sachin");
    t.insert("sandeep");
    t.print();
    if(t.search("gar")) cout<<"String Found"<<endl;
    else cout<<"String Not Found"<<endl;
    t.Delete("sagar");
    if(t.search("agar")) cout<<"String Found"<<endl;
    else cout<<"String Not Found"<<endl;
    t.print();
}