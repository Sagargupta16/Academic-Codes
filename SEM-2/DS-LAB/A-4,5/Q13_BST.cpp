#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    TreeNode *BstInsert(int d, TreeNode *r)
    {
        if (r == NULL)
        {
            TreeNode *a = new TreeNode(d);
            return a;
        }
        else if (r->data > d)
        {
            if (r->left == NULL)
            {
                TreeNode *a = new TreeNode(d);
                r->left = a;
            }
            else
            {
                BstInsert(d, r->left);
            }
        }
        else if (r->data < d)
        {
            if (r->right == NULL)
            {
                TreeNode *a = new TreeNode(d);
                r->right = a;
            }
            else
            {
                BstInsert(d, r->right);
            }
        }
        return r;
    } // O(Log(n))

    TreeNode *BstDelete(int key, TreeNode *r)
    {
        TreeNode *a = r;
        while (r != NULL)
        {
        }
    }

    TreeNode *CreateTree()
    {
        int n, x;
        cout << "Enter Number of Elements : ";
        cin >> n;
        cout << "Enter " << n << " Elements : ";
        TreeNode *a = NULL;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a = BstInsert(x, a);
        }
        return a;
    } // O(nLog(n))

    TreeNode *RSearch(TreeNode *r, int key)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->data == key)
        {
            return r;
        }
        else if (r->data < key)
        {
            return RSearch(r->right, key);
        }
        else
        {
            return RSearch(r->left, key);
        }
    } // O(Log(n))

    void InorderDisplay(TreeNode *r)
    {
        if (r == NULL){
            return;
        }
        InorderDisplay(r->left);
        cout << r->data << " ";
        InorderDisplay(r->right);
    } // O(n)

    int MinimumKey(TreeNode *r){
        while(r->left!=NULL){
            r=r->left;
        }
        return r->data;
    }

    int MaximumKey(TreeNode *r){
        while(r->right!=NULL){
            r=r->right;
        }
        return r->data;
    }
};

int main()
{
    TreeNode *root = NULL;
    TreeNode *a = NULL;
    Tree T;

    int c, x;
    cout << "----TREE MENU----" << endl;
    cout << "1. Create a BST " << endl;
    cout << "2. Insert in BST " << endl;
    cout << "3. Delete in BST " << endl;
    cout << "4. Search in BST " << endl;
    cout << "5. Display a BST " << endl;
    cout << "6. Minimum Element in a BST " << endl;
    cout << "7. Maximum Element in a BST " << endl;
    cout << "8. Quit " << endl;

    do
    {
        cout << "Enter your Choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            root = T.CreateTree();
            break;

        case 2:
            cout << "Enter data You want to Insert : ";
            cin >> x;
            T.BstInsert(x, root);
            break;

        case 3:
            break;

        case 4:
            cout << "Enter Data You want to Search : ";
            cin >> x;
            a = T.RSearch(root, x);
            if (a == NULL)
            {
                cout << "Key Not Found!" << endl;
            }
            else
            {
                cout << "Key Found!" << endl;
            }
            break;

        case 5:
            T.InorderDisplay(root);
            cout << endl;
            break;

        case 6: 
            cout<<"Min. Element is : "<<T.MinimumKey(root)<<endl;
            break;

        case 7:
            cout<<"Max. Element is : "<<T.MaximumKey(root)<<endl;
            break;

        case 8:
            break;

        default:
            cout << "Enter Valid Choice ! " << endl;
            break;
        }

    } while (c != 8);

    return 0;
}