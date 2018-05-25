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

	short type;

	int counter = 0;

	int lastCounter;

    void FillTree();

    void ClearTree(node* Ptr);

    void ShowSize();

    void EmptyCheck(node* Ptr);

	search FindKey(T key);

	void FindKeyHelper(T searchKey);

    node* CreateLeaf(T key);

    bool AddLeaf(T key, node* Ptr);

    void AddNewLeaf();

    void DeleteLeaf(T key);

	vector<T> SortInOrder(node* Ptr);

    void PrintPostOrder(node* Ptr);

    void PrintInOrder();

	void MergePrepare();

	node* MergeSubtree(node* Ptr, bool isLeft);

	unsigned int GenerateTree(unsigned int size, short type);

	void DrawTree(node* Ptr, int space);

	void TestTree(short type);

public:
	BST();
    ~BST();

    void MainMenu(short type);

	void IteratorMenu();
};

#endif
