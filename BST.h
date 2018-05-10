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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
	//vector<node*> TreeKeys;
	vector<node*> SortedKeys;
>>>>>>> parent of ec39690... wip MergeSubtrees
=======
	//vector<node*> TreeKeys;
	//vector<node*> SortedKeys;
>>>>>>> parent of 9782135... wip MergeSubtrees
=======
	//vector<node*> TreeKeys;
	//vector<node*> SortedKeys;
>>>>>>> parent of 9782135... wip MergeSubtrees
	typename vector<node*>::iterator iterator;
	//
	//

	//class ItBST
	//{
	//private:
	//	//node* Ptr;
	//	using Nodes = vector<node*>;
	//	void store_sorted_nodes(node* Ptr);
	//	Nodes nodes;
	//	typename Nodes::size_type current { 0 };

	//public:
	//	// Iterator traits, previously from std::iterator.
	//	using value_type = T;
	//	using difference_type = ptrdiff_t;
	//	using pointer = T*;
	//	using reference = T&;
	//	using iterator_category = bidirectional_iterator_tag;

	//	// Default constructible.
	//	ItBST() = default;
	//	explicit ItBST(node* Ptr);

	//	// Dereferencable.
	//	reference operator*() const;

	//	// Pre- and post-incrementable.
	//	ItBST& operator++();
	//	ItBST operator++(int);

	//	// Pre- and post-decrementable.
	//	ItBST& operator--();
	//	ItBST operator--(int);

	//	// Equality / inequality.
	//	bool operator==(const ItBST& rhs);
	//	bool operator!=(const ItBST& rhs);




<<<<<<< HEAD

	////	iterator() : Ptr(0) {}
	////	iterator(node* pn) : Ptr(pn) {}

	////	// Установка на корень дерева
	////	iterator& GoRoot()

	////		int operator*()
	////	{
	////		return Ptr->key;
	////	}

	////	iterator& operator++() // Для ++it
	////	{
	////		Ptr = pt->next;
	////		return *this;
	////	}

	////	iterator operator++(int) // Для it++
	////	{
	////		iterator tmp = *this;
	////		pt = pt->next;
	////		return tmp;
	////	}
	//};



	//void IteratorMenu();

	/*void ClearVector();*/

    node* root;

=======

	////	iterator() : Ptr(0) {}
	////	iterator(node* pn) : Ptr(pn) {}

	////	// Установка на корень дерева
	////	iterator& GoRoot()

	////		int operator*()
	////	{
	////		return Ptr->key;
	////	}

	////	iterator& operator++() // Для ++it
	////	{
	////		Ptr = pt->next;
	////		return *this;
	////	}

	////	iterator operator++(int) // Для it++
	////	{
	////		iterator tmp = *this;
	////		pt = pt->next;
	////		return tmp;
	////	}
	//};



	//void IteratorMenu();

	/*void ClearVector();*/

    node* root;

>>>>>>> parent of 9782135... wip MergeSubtrees
	//node* ReturnNodePrivate(node* Ptr);

    void FillTree();

    void ClearTree();

    void ShowSize();

    void EmptyCheck(node* Ptr);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	node* FindByKey(T key);
=======
    void FindByKey(T key, node* Ptr);
>>>>>>> parent of ec39690... wip MergeSubtrees
=======
	node* FindByKey(T key);//, node* Ptr);
>>>>>>> parent of 9782135... wip MergeSubtrees
=======
	node* FindByKey(T key);//, node* Ptr);
>>>>>>> parent of 9782135... wip MergeSubtrees

    node* CreateLeaf(T key);

    void AddLeaf(T key, node* Ptr);

    void AddNewLeaf();

    void DeleteLeaf(T key);

	void SortInOrder(node* Ptr);

    void PrintPostOrder(node* Ptr);

    void PrintInOrder();

<<<<<<< HEAD
	void MergeSubtrees(T key);

<<<<<<< HEAD
<<<<<<< HEAD
	void GenerateTree();

=======
>>>>>>> parent of ec39690... wip MergeSubtrees
=======
>>>>>>> parent of 9782135... wip MergeSubtrees
=======
>>>>>>> parent of 9782135... wip MergeSubtrees
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
