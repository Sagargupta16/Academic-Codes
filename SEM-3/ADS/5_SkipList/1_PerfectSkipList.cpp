#include<iostream>
using namespace std;

#define INT_MAX 9999999
#define INT_MIN -9999999
class Node {
public:
    int key;
    Node* next;
    Node* down;
    Node* up;
    Node* prev;
    Node(int key) {
        this->key = key;
        next = down = up = prev = NULL;
    }
};

class SkipList {
public:
    Node* head;
    Node* tail;
    int maxLevel;
    int size;
    SkipList() {
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
        maxLevel = 0;
        size = 0;
    }
    void create(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insert(arr[i],i,n);
        }
    }
    void insert(int key,int i,int n) {
        Node* node = new Node(key);
        Node* cur = head;
        while (cur) {
            while (cur->next->key < key) {
                cur = cur->next;
            }
            if (cur->down)cur = cur->down;
            else break;
        }
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
        size++;
        int level = 0;
        while (i%2) {
            if (level >= maxLevel) {
                Node* newHead = new Node(INT_MIN);
                Node* newTail = new Node(INT_MAX);
                newHead->next = newTail;
                newTail->prev = newHead;
                newHead->down = head;
                newTail->down = tail;
                head->up = newHead;
                tail->up = newTail;
                head = newHead;
                tail = newTail;
                maxLevel++;
            }
            while (cur->up == NULL) {
                cur = cur->prev;
            }
            cur = cur->up;
            Node* newNode = new Node(key);
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next->prev = newNode;
            cur->next = newNode;
            newNode->down = node;
            node->up = newNode;
            node = newNode;
            level++;
            i/=2;
        }
    }
    bool search(int key) {
        Node* cur = head;
        while (cur) {
            while (cur->next->key < key) {
                cur = cur->next;
            }
            if (cur->down) cur = cur->down;
            else break;
        }
        return cur->next->key == key;
    }
    void print() {
        Node* cur = head;
        while (cur->down) {
            cur = cur->down;
        }
        int level = 0;
        int x = size;
        while (x>0) {
            cout << "Level " << level << ": ";
            Node* temp = cur;
            while (temp) {
                cout << temp->key << " ";
                temp = temp->next;
            }
            cout << endl;
            cur = cur->up;
            level++;
            x=x/2;
        }
    }
};

int main() {
    SkipList* skipList = new SkipList();
    int arr[] = { 41,14,17,15,12,16,13,19,18,11,20,10,354};
    int n = sizeof(arr) / sizeof(arr[0]);
    skipList->create(arr, n);
    skipList->print();

    cout<<endl;

    cout<<"Search 19: "<<skipList->search(19)<<endl;
    cout<<"Search 21: "<<skipList->search(21)<<endl;
    return 0;
}
