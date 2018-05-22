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

	struct search
	{
		node* nodeptr;
		node* parent;
		bool isLeft;
	};

	typename vector<T>::iterator iterator;

    node* root;

	int counter;

    void FillTree();

    void ClearTree(node* Ptr);

    void ShowSize();

    void EmptyCheck(node* Ptr);

	search FindKey(T key);

	void FindKeyHelper(T searchKey);

    node* CreateLeaf(T key);

    void AddLeaf(T key, node* Ptr);

    void AddNewLeaf();

    void DeleteLeaf(T key);

	vector<T> SortInOrder(node* Ptr);

    void PrintPostOrder(node* Ptr);

    void PrintInOrder();

	void MergePrepare();

	node* MergeSubtree(node* Ptr, bool isLeft);

	void GenerateTree();

	void DrawTree(node* Ptr, int space);

public:
	BST();
    ~BST();

    void MainMenu();

	void IteratorMenu();
};

#endif
