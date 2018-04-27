#ifndef BST_H
#define BST_H

using namespace std;

template <typename T> class BST
{
private:
    struct node
    {
        T key;
        node* left;
        node* right;
    };

	vector<node*> TreeKeys = new vector<node*>;

	//class iterator
	//{
	//	node* Ptr;
	//	//vector<node*> vPt;

	//public:
	//	iterator() : Ptr(0) {}
	//	iterator(node* pn) : Ptr(pn) {}
	//	
	//	T operator*()
	//	{
	//		return Ptr->key
	//	}

	//	
	//};

    node* root;

    void FillTree();

    void ClearTree();

    void ShowSize();

    void EmptyCheck(node* Ptr);

    void FindByKey(T key, node* Ptr);

    node* CreateLeaf(T key);

    void AddLeaf(T key, node* Ptr);

    void AddNewLeaf();

    void DeleteLeaf(T key);

	//vector<node*> SortInOrder(node* Ptr);

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

	//void ItrStandOnRoot(node* Ptr);

	//void ItrCheckEnd(node* Ptr);
/*
    int ReturnRootKey();

    void PrintChildren(int key);

    int FindSmallest();

    void RemoveNode(int key);
*/
};

#endif // BST_H
