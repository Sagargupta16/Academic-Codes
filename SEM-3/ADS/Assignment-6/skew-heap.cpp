#include <iostream>
using namespace std;

struct SkewHeap
{
    int key;
    SkewHeap *right;
    SkewHeap *left;
    SkewHeap()
    {
        key = 0;
        right = NULL;
        left = NULL;
    }
    SkewHeap *merge(SkewHeap *h1, SkewHeap *h2)
    {
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;
        if (h1->key > h2->key)
            swap(h1, h2);
        swap(h1->left, h1->right);
        h1->left = merge(h2, h1->left);

        return h1;
    }
    SkewHeap *construct(SkewHeap *root,
                        int heap[], int n)
    {
        SkewHeap *temp;
        for (int i = 0; i < n; i++)
        {
            temp = new SkewHeap;
            temp->key = heap[i];
            root = merge(root, temp);
        }
        return root;
    }
    void inorder(SkewHeap *root)
    {
        if (root == NULL)
            return;
        else
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
        return;
    }
};
int main()
{
    SkewHeap heap, *temp1 = NULL,*temp2 = NULL;
    int heap1[] = {12, 5, 10};
    int heap2[] = {3, 7, 8, 14};
    int n1 = sizeof(heap1) / sizeof(heap1[0]);
    int n2 = sizeof(heap2) / sizeof(heap2[0]);
    temp1 = heap.construct(temp1, heap1, n1);
    temp2 = heap.construct(temp2, heap2, n2);
    temp1 = heap.merge(temp1, temp2);
    cout << "Merged Heap is: " << endl;
    heap.inorder(temp1);
}
