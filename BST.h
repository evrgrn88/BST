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
        node* parent;
    };

    struct nodeArray
    {
        int arraySize = 0;
        int a[];
    };

    nodeArray* TreeKeys = new nodeArray;

    nodeArray* InOrderKeys = new nodeArray;

    nodeArray* PostOrderKeys = new nodeArray;

    node* root;

    void FillTree();

    int ShowSizePrivate(node* Ptr);

    void ClearTree(node* Ptr);//Private(node* Ptr);

    void ClearArray(nodeArray* Arr);

    void EmptyCheckPrivate(node* Ptr);

    //void SortTreeArray();

    void FindByKey(int key);

    void AddLeafPrivate(int key, node* Ptr);

    void SortInOrder(node* Ptr);

    void PrintInOrder();//Private(node* Ptr);

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

//    void ClearTree();

    void EmptyCheck();

//    void FindByKey();

//    void AddLeaf(int key);

//    void PrintInOrder();

    int ReturnRootKey();

    void PrintChildren(int key);

    int FindSmallest();

    void RemoveNode(int key);



};

#endif // BST_H
