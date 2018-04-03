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
            "2. Print the tree in order.\n" <<
            "3. Show tree size.\n" <<
            "4. Clear the tree.\n" <<
            "5. Check if the tree is empty.\n" <<
            "6. Search element.\n" <<
            "7. Add new element.\n" <<
            "8. Delete element.\n" <<
            "9. Use the operation iterator.\n" <<
            "10. Traverse the tree (Lt -> Rt -> t).\n" <<
            "11. Print tree array.\n" <<
            //"11. Merge two subtrees recursively.\n" <<
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
        cout << "\nThe tree was cleared.\n";
        break;

    case 5:
        EmptyCheck();
        break;

    case 6:
        int search;

        cout << "\nSearch: ";
        cin >> search;
        cout << endl;

        FindByKey(search);

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
        for(int i = 0; i < TreeKeys->arraySize; i++)
        {
            cout << TreeKeys->a[i];
        }

        //cout << "Merge two subtrees recursively!";
        break;
    }

    cout << endl << endl;
    system("pause");

    ShowMenu();
}

void BST::FillTree()
{
    ClearTreePrivate(root);

    cout << "\nEnter tree size: \n";
    cin >> TreeKeys->arraySize;
    cout << endl;

    int i = 0;

    while(i < TreeKeys->arraySize)
    {
        cout << "\nEnter an element: \n";
        cin >> TreeKeys->a[i];
        AddLeafPrivate(TreeKeys->a[i], root);
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

void BST::ClearTree()
{
    ClearTreePrivate(root);
}

void BST::ClearTreePrivate(node* Ptr)
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
    else
    {
        cout << "\nThe tree is empty.\n";
    }



//    return -1;



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

// Пузырьковая сортировка
void BST::SortTreeArray()
{
    int temp;

    for (int i = 0; i < TreeKeys->arraySize - 1; i++)
    {
        for (int j = 0; j < TreeKeys->arraySize - i - 1; j++)
        {
            if (TreeKeys->a[j] > TreeKeys->a[j + 1])
            {
                temp = TreeKeys->a[j];
                TreeKeys->a[j] = TreeKeys->a[j + 1];
                TreeKeys->a[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < TreeKeys->arraySize; i++)
    {
        cout << TreeKeys->a[i] << " ";
    }
}

void BST::FindByKey(int key)
{
    SortTreeArray();

    int average_index = 0;// переменная для хранения индекса среднего элемента массива
    int first_index = 0; // индекс первого элемента в массиве
    int last_index = TreeKeys->arraySize - 1; // индекс последнего элемента в массиве

    if(last_index == -1)
        cout << "\nThe tree is empty" << endl; // массив пуст

    while(first_index < last_index)
    {
        average_index = first_index + (last_index - first_index) / 2; // меняем индекс среднего значения
        key <= TreeKeys->a[average_index] ?
                    last_index = average_index :
                    first_index = average_index + 1;    // найден ключевой элемент или нет
    }

    if(TreeKeys->a[last_index] == key)
        cout << "\nElement is found\n";
    else
        cout << "\nElement is not found" << endl;
}

BST::node* BST::CreateLeaf(int key)
{
    node* n = new node;

    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;

    return n;
}

//void BST::AddLeaf(int key)
//{
//    AddLeafPrivate(key, root);
//}

void BST::AddLeafPrivate(int key, node* Ptr)
{
    if(root == NULL)
    {
        root = CreateLeaf(key);
    }
    else
    {
        // x — корень поддерева, z — вставляемый элемент

        while(Ptr != NULL)
        {
            if(key == Ptr->key)
            {
                cout << "\nThe value already exists!";
                break;
            }
            else
            {
                if(key > Ptr->key)
                {
                    if(Ptr->right != NULL)
                    {
                        Ptr = Ptr->right;
                    }
                    else
                    {
                        Ptr->right = CreateLeaf(key);
                        Ptr->right->parent = Ptr;
                        break;
                    }
                }
                else if(key < Ptr->key)
                {
                    if(Ptr->left != NULL)
                    {
                        Ptr = Ptr->left;
                    }
                    else
                    {
                        Ptr->left = CreateLeaf(key);
                        Ptr->left->parent = Ptr;
                        break;
                    }
                }
            }
        }
    }



}

//    if(root == NULL)
//    {
//        root = CreateLeaf(key);
//    }
//    else
//    {
//        if(key < Ptr->key)
//        {
//            if(Ptr->left != NULL)
//            {
//                AddLeafPrivate(key, Ptr->left);
//            }
//            else
//            {
//                Ptr->left = CreateLeaf(key);
//            }
//        }
//        else
//        {
//            if(key > Ptr->key)
//            {
//                if(Ptr->right != NULL)
//                {
//                    AddLeafPrivate(key, Ptr->right);
//                }
//                else
//                {
//                    Ptr->right = CreateLeaf(key);
//                }
//            }
//            else
//            {
//                cout << "The key " << key << " has already been added to the tree\n";
//            }
//        }
//    }


void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
	int i = 0;

    if(root != NULL)
    {
        //1 - Go Left
        if(Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left);
        }

        //2 - Process Node, in this case print
        
        i++;
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
