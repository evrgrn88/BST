//#ifndef BST_H
//#define BST_H


class BST
{
private:
    struct node
    {
        int key;
        node* left;
        node* right;
    };

    node* root;

    void FillTree();

    int ShowSizePrivate(node* Ptr);

    int ClearTreePrivate(node* Ptr);

    void EmptyCheckPrivate(node* Ptr);

    void FindByKeyPrivate(int key, node* Ptr);

    void AddLeafPrivate(int key, node* Ptr);

    void PrintInOrderPrivate(node* Ptr);

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

    int ClearTree();

    void EmptyCheck();

    void FindByKey(int key);

    void AddLeaf(int key);

    void PrintInOrder();

    int ReturnRootKey();

    void PrintChildren(int key);

    int FindSmallest();

    void RemoveNode(int key);



};

//#endif // BST_H
