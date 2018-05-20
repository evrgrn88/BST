#ifndef BST_H
#define BST_H

//#include <iterator>
//#include <vector>

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

	//vector<node*> TreeKeys;
	//vector<node*> SortedKeys;
	typename vector<T>::iterator iterator;

    node* root;

	//node* ReturnNodePrivate(node* Ptr);

    void FillTree();

    void ClearTree(node* Ptr);

    void ShowSize();

    void EmptyCheck(node* Ptr);

	node* FindByKey(T key);//, node* Ptr);

    node* CreateLeaf(T key);

    void AddLeaf(T key, node* Ptr);

    void AddNewLeaf();

    void DeleteLeaf(T key);

	vector<T> SortInOrder(node* Ptr);

    void PrintPostOrder(node* Ptr);

    void PrintInOrder();

	void MergePrepare();

	node* MergeSubtree(node* Parent, node* Ptr, short isLeft);

	void GenerateTree();

	void DrawTree(T key);
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
