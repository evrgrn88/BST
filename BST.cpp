#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

#include "BST.h"

using namespace std;


BST::BST()
{
    root = NULL;
}

void BST::ShowMenu()
{
    system("cls");

    short choice;
    cout << endl <<
            "1. Create a new tree.\n" <<
            "2. Print the tree (in-order).\n" <<
            "3. Show tree size.\n" <<
            "4. Clear the tree.\n" <<
            "5. Check if the tree is empty.\n" <<
            "6. Search element.\n" <<
            "7. Add new element.\n" <<
            "8. Delete element.\n" <<
            "9. Use the operation iterator.\n" <<
            "10. Traverse the tree (Lt -> Rt -> t).\n" <<
            "11. Merge two subtrees recursively.\n" <<
            "\n\nChoose your operation: ";

    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        FillTree();
        break;

    case 2:
        PrintInOrder();
        break;

    case 3:
        cout << "The tree consists of " <<
                ShowSize() << " elements.\n";
        break;

    case 4:
        ClearTree();
        cout << "The tree is cleared.\n";
        break;

    case 5:
        EmptyCheck();
        break;

    case 6:
        cout << "Search: ";

        int SearchKey;
        cin >> SearchKey;
        cout << endl;

        FindByKey(SearchKey);


        break;

    case 7:
        cout << "Add new element!";
        break;

    case 8:
        cout << "Delete element!";
        break;

    case 9:
        cout << "Use the operation iterator!";
        break;

    case 10:
        cout << "Traverse the tree (Lt -> Rt -> t)!";
        break;

    case 11:
        cout << "Merge two subtrees recursively!";
        break;
    }

    cout << endl << endl;
    system("pause");

    ShowMenu();
}

void BST::FillTree()
{
    ClearTreePrivate(root);

    int TreeSize = 0;
    cout << "\nEnter tree size: \n";
    cin >> TreeSize;
    cout << endl;

    int TreeKeys[TreeSize];

    int i = 0;

    while(i < TreeSize)
    {
        cout << "\nEnter an element: \n";
        cin >> TreeKeys[i];
        AddLeafPrivate(TreeKeys[i], root);
        cout << endl;
        i++;
    }
}

int BST::ShowSize()
{
    return ShowSizePrivate(root);
}

int BST::ShowSizePrivate(node* Ptr)
{
    int count = 0;

    stack<node*> s;
    s.push(NULL);

    do
    {
        if(Ptr != NULL)
        {
            s.push(Ptr);
            count++;
            Ptr = Ptr->left;
        }
        else
        {
            if(s.top() == NULL)
            {
                break;
            }

            Ptr = s.top();
            s.pop();
            Ptr = Ptr->right;
        }
    }
    while(true);

    return count;
}

int BST::ClearTree()
{
    return ClearTreePrivate(root);
}

int BST::ClearTreePrivate(node* Ptr)
{
    if(root != NULL)
    {
        queue<node*> q;

        q.push(root);

        while(!q.empty())
        {
            Ptr = q.front();
            q.pop();

            if(Ptr->left != NULL)
            {
                q.push(Ptr->left);
            }

            if(Ptr->right != NULL)
            {
                q.push(Ptr->right);
            }

            root = NULL;
        }
    }

    return -1;



}

void BST::EmptyCheck()
{
    return EmptyCheckPrivate(root);
}

void BST::EmptyCheckPrivate(node* Ptr)
{
    if(Ptr == NULL)
    {
        cout << "\nThe tree is empty.\n";
    }
    else
    {
        cout << "\nThe tree is NOT empty\n";
    }

    cout << endl;
}

void BST::FindByKey(int key)
{
    FindByKeyPrivate(key, root);
}

void BST::FindByKeyPrivate(int key, node* Ptr)
{
    if(root != NULL)
    {
        stack<node*> s;
        s.push(root);



        if(!s.empty())
        {
            node* x = s.top();
            cout << "Top: " << x->key << "\nRoot: " << root->key << "\nPtr: " << Ptr->key << endl;
            system("pause");

            while(Ptr != NULL)
            {
                Ptr = Ptr->left;
                cout << Ptr->key;
                s.push(Ptr);

            }

            if(Ptr->right == NULL)
            {
                if(Ptr->key == key)
                {
                    cout << "The element " << key << " exists in the tree.\n";
                }
                else
                {
                    s.pop();
                    Ptr = s.top();
                }
            }
            else
            {
                s.push(Ptr->right);
                Ptr = Ptr->right;
            }
        }
        else
        {
            cout << "The element " << key << " does NOT exist in the tree.\n";
        }
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}

BST::node* BST::CreateLeaf(int key)
{
    node* n = new node;

    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
    if(root == NULL)
    {
        root = CreateLeaf(key);
    }
    else
    {
        if(key < Ptr->key)
        {
            if(Ptr->left != NULL)
            {
                AddLeafPrivate(key, Ptr->left);
            }
            else
            {
                Ptr->left = CreateLeaf(key);
            }
        }
        else
        {
            if(key > Ptr->key)
            {
                if(Ptr->right != NULL)
                {
                    AddLeafPrivate(key, Ptr->right);
                }
                else
                {
                    Ptr->right = CreateLeaf(key);
                }
            }
            else
            {
                cout << "The key " << key << " has already been added to the tree\n";
            }
        }
    }
}

void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
    if(root != NULL)
    {
        //1 - Go Left
        if(Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }

        //2 - Process Node, in this case print
        cout << Ptr->key << "  ";

        //3 - Go Right
        if(Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty.\n";
    }
}

BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if(key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }

}

int BST::ReturnRootKey()
{
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void BST::PrintChildren(int key)
{
    node* Ptr = ReturnNode(key);

    if(Ptr !=NULL)
    {
        cout << "Parent node = " << Ptr->key << endl;

        Ptr->left == NULL ?
                    cout << "Left child = NULL\n" :
                    cout << "Left child = " << Ptr->left->key << endl;

        Ptr->right == NULL ?
                    cout << "Right child = NULL\n" :
                    cout << "Right child = " << Ptr->right->key << endl;

    }
    else
    {
        cout << "Key " << key << " is not in the tree\n";
    }
}

int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
    if(root == NULL)
    {
        cout << "The tree is empty\n";
        return -1000;
    }
    else
    {
        if(Ptr->left != NULL)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        else
        {
            return Ptr->key;
        }
    }
}

void BST::RemoveNode(int key)
{
    return RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
    if(root != NULL)
    {
        if(root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if(key < parent->key && parent->left != NULL)
            {
                parent->left->key == key ?
                            RemoveMatch(parent, parent->left, true) :
                            RemoveNodePrivate(key, parent -> left);
            }
            else if(key > parent->key && parent->right != NULL)
            {
                parent->right->key == key ?
                            RemoveMatch(parent, parent->right, false) :
                            RemoveNodePrivate(key, parent -> right);
            }
            else
            {
                cout << "The key " << key << " was not found in the tree\n";
            }
        }
    }
    else
    {
        cout << "The tree is empty\n";
    }
}

void BST::RemoveRootMatch()
{
    if(root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // 0-0 children
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }

        // 1-1 child
        else if(root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << "was deleted. " <<
                    "The new root contains key " << root->key << endl;
        }
        else if(root->right != NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << "was deleted. " <<
                    "The new root contains key " << root->key << endl;
        }

        // 2-2 Children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey <<
                    " was overwritten with key " << root->key << endl;
        }
    }
    else
    {
        cout << "Can not remove root. The tree is empty\n";
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
    if(root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // 0-0
        if(match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true ?
                        parent->left = NULL:
                        parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }

        // 1-1
        else if(match->left == NULL && match->right != NULL)
        {
            left == true ?
                        parent->left = match->right:
                        parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        else if(match->left != NULL && match->right == NULL)
        {
            left == true ?
                        parent->left = match->left:
                        parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }

        // 2-2
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty\n";

    }
}




BST::~BST()
{
    //RemoveSubtree(root);
}

// Post-order traversal
void BST::RemoveSubtree(node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->left != NULL)
        {
            RemoveSubtree(Ptr->left);
        }
        if(Ptr->right != NULL)
        {
            RemoveSubtree(Ptr->right);
        }
        cout << "Deleting the node containing key " << Ptr->key << endl;
        delete Ptr;
    }
}
