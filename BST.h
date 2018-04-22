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

    node* root;

    void FillTree();

    void ClearTree();

    void ShowSize();

    void EmptyCheck(node* Ptr);

    void FindByKey(int key, node* Ptr);

    node* CreateLeaf(int key);

    void AddLeaf(int key, node* Ptr);

    void AddNewLeaf();

    void DeleteLeaf(int key);

    void PrintPostOrder(node* Ptr);

    void PrintInOrder(node* Ptr);

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

/*
    int ReturnRootKey();

    void PrintChildren(int key);

    int FindSmallest();

    void RemoveNode(int key);
*/
};

#endif // BST_H
