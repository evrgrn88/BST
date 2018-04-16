#ifndef BST_H
#define BST_H


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

    nodeArray* TreeKeys = new nodeArray;
    nodeArray* PostOrderKeys = new nodeArray;

    node* root;

    void FillTree();

    int ShowSizePrivate(node* Ptr);

    void ClearTree(node* Ptr);

    void ClearArray(nodeArray* Arr);

    void EmptyCheckPrivate(node* Ptr);

    void FindByKey(int key);

    void AddLeafPrivate(int key, int pos, node* Ptr);

    void AddNewLeaf();

    nodeArray* SortInOrder(node* Ptr);

    void PrintInOrder();

    node* ReturnNodePrivate(int key, node* Ptr);

    int FindSmallestPrivate(node* Ptr);

    void RemoveNodePrivate(int key, node* parent);

    void RemoveRootMatch();

    void RemoveMatch(node* parent, node* match, bool left);

    node* CreateLeaf(int key);

    node* ReturnNode(int key);

    void RemoveSubtree(node* Ptr);

public:
    BST();
    ~BST();

    void ShowMenu();

    int ShowSize();

    void EmptyCheck();

    int ReturnRootKey();

    void PrintChildren(int key);

    int FindSmallest();

    void RemoveNode(int key);



};

#endif // BST_H
