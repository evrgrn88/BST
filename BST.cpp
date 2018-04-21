/*
TODO:

Удаление элемента

Итератор:
Установка на корень
Проверка конца
Доступ к данным текущего элемента
Переход к следующему по значению ключа элементу
Переход к предыдущему по значению ключа элементу

Обход Post-Order

Объединение двух поддеревьев (рекурсивно)

Вывод структуры на экран

Опрос числа просмотренных нод (в каждую операцию?)

!Перевести текст на русский!
Перейти на unicode
*/



#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>

#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
    
}

void BST::ShowMenu()
{
    while(true)
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
            ClearTree(root);
            break;

        case 5:
            EmptyCheck(root);
            break;

        case 6:
            int search;
            node* result;

            cout << "\nSearch: ";
            cin >> search;
            cout << endl;

            result = FindByKey(search, root);

            break;

        case 7:
            AddNewLeaf();
            break;

        case 8:
            int deleteKey;
            node* DeletionResult;

            cout << "Enter a key to delete: ";
            cin >> deleteKey;

            DeletionResult = DeleteLeaf(deleteKey, root);

            break;

        case 9:
            cout << "Use the operation iterator!";
            break;

        case 10:
            cout << "Traverse the tree (Lt -> Rt -> t)!";
            break;

        case 11:
            for(int i = 0; i < TreeKeys.size(); i++)
            {
                cout << TreeKeys.at(i) << " ";
            }

            //cout << "Merge two subtrees recursively!";
            break;
        }

        cout << endl << endl;
        system("pause");
    }
}

void BST::FillTree()
{
    ClearTree(root);
    int treeSize;

    cout << "\nEnter tree size: \n";
    cin >> treeSize;
    cout << endl;

    for(int i = 0; i < treeSize; i++)
    {
        AddNewLeaf();
    }
}

int BST::ShowSize()
{
    return TreeKeys.size();
}

void BST::ClearTree(node* Ptr)
{
    if(Ptr != NULL)
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
        }

        root = NULL;

        TreeKeys.clear();
        TreeKeys.shrink_to_fit();

        cout << "\nThe tree was cleared.\n";
    }
}

void BST::EmptyCheck(node* Ptr)
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

BST::node* BST::FindByKey(int key, node* Ptr)
{
    if(root != NULL)
    {
        while(Ptr != NULL)
        {
            if(Ptr->key == key)
            {
                break;
            }

            if(key > Ptr->key)
            {
                Ptr = Ptr->right;
            }
            else if(key < Ptr->key)
            {
                Ptr = Ptr->left;
            }
        }

        if(Ptr == NULL)
        {
            cout << "\nElement is NOT found\n";
            return Ptr;
        }

        if(Ptr->key == key)
        {
            cout << "\nElement is found\n";
            return Ptr;
        }
    }
    else
    {
        cout << "\nThe tree is empty.\n";
        return Ptr;
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

void BST::AddLeaf(int key, node* Ptr)
{
    if(root == NULL)
    {
        root = CreateLeaf(key);
    }
    else
    {
        while(Ptr != NULL)
        {
            if(key == Ptr->key)
            {
                cout << "\nThe value already exists!\nType the new value: ";
                cin >> key;
                TreeKeys.pop_back();
                TreeKeys.push_back(key);
                Ptr = root;
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
                        break;
                    }
                }
            }
        }
    }
}

void BST::AddNewLeaf()
{
    int newKey;
    cout << "\nEnter an element: \n";
    cin >> newKey;
    TreeKeys.push_back(newKey);
    AddLeaf(TreeKeys.back(), root);
    cout << endl;
}

BST::node* BST::DeleteLeaf(int key, node* Ptr)
{
    if(root != NULL)
    {
        node* Parent;
        node* Child;
        node* ParentReplacement;
        node* NodeReplacement;

        int isLeft = 0; // 1 for left. 0 for right

        while(Ptr != NULL)
        {
            if(key == Ptr->key)
            {
                break;
            }

            if(key > Ptr->key)
            {
                Parent = Ptr;
                isLeft = 0; // Right
                Ptr = Ptr->right;
            }
            else if(key < Ptr->key)
            {
                Parent = Ptr;
                isLeft = 1; // Left
                Ptr = Ptr->left;
            }
        }

        if(Ptr == NULL)
        {
            cout << "\nElement is NOT found\n";
            return Ptr;
        }

        if(Ptr->key == key)
        {
            cout << "\nElement is found. Deleting... ";

            if(Ptr->left == NULL && Ptr->right == NULL) // 0 children
            {
                if(Parent == NULL) // Node is a root
                {
                    free(Ptr);
                    root = NULL;

                    cout << "done.";

                    return Ptr;
                }
                else
                {
                    free(Ptr);
                    if(isLeft)
                    {
                        Parent->left = NULL;
                    }
                    else
                    {
                        Parent->right = NULL;
                    }
                }
            }

            if(Ptr->left == NULL || Ptr->right == NULL) // 1 child
            {
                if(Ptr->left != NULL)
                {
                    Child = Ptr->left;
                }
                else
                {
                    Child = Ptr->right;
                }

                if(Parent == NULL) // Root node is being deleted
                {
                    root = Child;
                    free(Ptr);
                }
                else // Deleting node, parent adopting node children
                {
                    if(isLeft)
                    {
                        Parent->left = Child;
                    }
                    else
                    {
                        Parent->right = Child;
                    }
                    free(Ptr);
                }
            }

            // 2 children
            // Finding replacement (highest node less than node to delete)
            ParentReplacement = Ptr;
            NodeReplacement = Ptr->left;
            isLeft = 1; // NodeReplacement is left child of parent

            while(NodeReplacement->right != NULL)
            {
                ParentReplacement = NodeReplacement;
                NodeReplacement = NodeReplacement->right;
                isLeft = 0; // NodeReplacement is right child of parent
            }

            Ptr->key = NodeReplacement->key; // Copying data

            if(isLeft) // NodeReplacement is left child of Ptr.
            {
                Ptr->left = NodeReplacement->left;
                free(NodeReplacement);
            }
            else // NodeReplacement is right grandchild of Ptr->left
            {
                ParentReplacement->right = NodeReplacement->left;
                free(NodeReplacement);
            }

            return Ptr;
        }
    }
    else
    {
        cout << "\nThe tree is empty.\n";
        return Ptr;
    }
}

vector<int> BST::SortInOrder(node* Ptr)
{
    vector<int> keys;

    if(Ptr != NULL)
    {
        stack<node*> s;
        s.push(NULL);

        do
        {
            if(Ptr != NULL)
            {
                s.push(Ptr);
                Ptr = Ptr->left;
            }
            else
            {
                if(s.top() == NULL)
                {
                    return keys;
                }

                Ptr = s.top();
                keys.push_back(Ptr->key);
                s.pop();
                Ptr = Ptr->right;
            }
        }
        while(true);
    }
    else
    {
        cout << "\nThe tree is empty.\n";
        return keys;
    }
}

void BST::PrintInOrder()
{
    if(root != NULL)
    {
        vector<int> InOrderKeys = SortInOrder(root);
        int vectorSize = InOrderKeys.size();

        cout << "Printing keys in order: \n";

        for(int i = 0; i < vectorSize; i++)
        {
            cout << InOrderKeys.at(i) << " ";
        }
    }
    else
    {
        cout << "\nThe tree is empty.\n";
    }
}

/*
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
*/

BST::~BST()
{

}
