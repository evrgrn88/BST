#ifndef BST_H
#define BST_H

using namespace std;

template <typename T> class BST
{
private:
	
	// Defining node structure
	struct node
    {
        T key;
        node* left;
        node* right;
    };

	// Search result structure
	// Contains pointers for a found node and parent node, and node position flag
	struct search
	{
		node* nodeptr;
		node* parent;
		bool isLeft;
	};

	// Iterator for vector element access
	typename vector<T>::iterator iterator;

    // Root node declaration
	node* root;

	// Global tree type variable
	short type;

	// Visited nodes counter initialization
	int counter = 0;

	// Manual tree creation
    void FillTree();

	// Clears the tree
    void ClearTree(node* Ptr);

	// Shows size of a tree
    void ShowSize();

	// Checks if a tree is empty
    void EmptyCheck(node* Ptr);

	// Search for a specific key
	search FindKey(T key);

	// Text interface for a search function
	void FindKeyHelper(T searchKey);

	// Creates a new node in a heap
    node* CreateLeaf(T key);

	// Adds new element. Returns true if element exists
    bool AddLeaf(T key, node* Ptr);

	// Text interface for manual node addition function
	void AddNewLeaf();

    // Node deletion with replacement
	void DeleteLeaf(T key);

	// In-order sorting
	vector<T> SortInOrder(node* Ptr);

	// Prints a sorted vector
	void PrintInOrder();

    // Post-order traversal
	void PrintPostOrder(node* Ptr);

	// Prepares for merging subtree
	void MergePrepare();

	// Recursively merges nearby subtrees
	node* MergeSubtree(node* Ptr, bool isLeft);

	// Generates a random tree
	unsigned int GenerateTree(unsigned int size, short type);

	// Shows tree structure
	void DrawTree(node* Ptr, int space);

	// Testing trees from 10 to 100000 random elements
	// Prints a median value for insert, search and delete operations
	void TestTree(short type);

	// Linear search in a vector
	bool LinearSearch(vector<T> v, T key);

	// Generates a random vector of specific size
	vector<T> GenerateVector(short type);

	// Create vector manually
	vector<T> EnterVector();

	// Bubble sort the vector
	vector<T> BubbleSort(short type, vector<T> vec);

	// Selection sort the vector
	vector<T> SelectionSort(short type, vector<T> vec);

	// Insertion sort the vector
	vector<T> InsertionSort(short type, vector<T> vec);

public:
	BST();
    ~BST();

    void MainMenu(short type);

	void IteratorMenu();
};

#endif