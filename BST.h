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

	typename vector<node*>::iterator iterator;

	node* root;

    void FillTree();

    void ClearTree(node* Ptr);

    void ShowSize();

    void EmptyCheck(node* Ptr);

	node* FindByKey(T key);

    node* CreateLeaf(T key);

    void AddLeaf(T key, node* Ptr);

    void AddNewLeaf();

	node* DeleteLeaf(T key, node* Ptr);

	vector<node*> SortInOrder(node* Ptr);

    void PrintPostOrder(node* Ptr);

    void PrintInOrder();

	void MergeSubtrees(T key);

	void GenerateTree();

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

	/*using iterator = ItBST;

	iterator begin() const;

	iterator end() const;*/

    void MainMenu();

	void IteratorMenu();

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
