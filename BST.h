#ifndef BST_H
#define BST_H

using namespace std;

class BST
{
private:
    struct node
    {
        int key;
        node* left;
        node* right;
    };

    struct nodeArray
    {
        int arraySize = 0;
        int a[];
    };

    vector<int> TreeKeys;

    node* root;

    void FillTree();

    void ClearTree(node* Ptr);

    void EmptyCheck(node* Ptr);

    node* FindByKey(int key, node* Ptr);

//    void FindByKey(int key);

    node* CreateLeaf(int key);

    void AddLeaf(int key, node* Ptr);

    void AddNewLeaf();

    node* DeleteLeaf(int key, node* Ptr);

    vector<int> SortInOrder(node* Ptr);

    void PrintInOrder();

    /*
    node* ReturnNodePrivate(int key, node* Ptr);

    int FindSmallestPrivate(node* Ptr);

    void RemoveNodePrivate(int key, node* parent);

    void RemoveRootMatch();

    void RemoveMatch(node* parent, node* match, bool left);

    node* ReturnNode(int key);

    void RemoveSubtree(node* Ptr);
    */

public:
    BST();
    ~BST();

    void ShowMenu();

    int ShowSize();

/*
    int ReturnRootKey();

    void PrintChildren(int key);

    int FindSmallest();

    void RemoveNode(int key);
*/
};

#endif // BST_H
