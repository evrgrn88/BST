#ifndef BST_H
#define BST_H

#include <iterator>

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

	
	

	/*class iterator
	{*/
	//	node* Ptr;

	//public:
	//	iterator() : Ptr(0) {}
	//	iterator(node* pn) : Ptr(pn) {}
	//	
	//	// Установка на корень дерева
	//	iterator& GoRoot()

	//	int operator*()
	//	{
	//		return Ptr->key;
	//	}

	//	iterator& operator++() // Для ++it
	//	{
	//		Ptr = pt->next;
	//		return *this;
	//	}

	//	iterator operator++(int) // Для it++
	//	{
	//		iterator tmp = *this;
	//		pt = pt->next;
	//		return tmp;
	//	}		
	//};

    node* root;

	node* ReturnNodePrivate(node* Ptr);

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
	// Iterator traits, previously from std::iterator.
	using value_type = T;
	using difference_type = ptrdiff_t;
	using pointer = T*;
	using reference = T&;
	using iterator_category = bidirectional_iterator_tag;

	node* begin();

	node* end();
	
	// Default constructible.
	//BST();
	//BstIterator() = default;
	//explicit BST(node* Ptr);

	// Dereferencable.
	reference operator*() const;
	
	// Pre- and post-incrementable.
	node& operator++();
	node operator++(int);

	// Pre- and post-decrementable.
	node& operator--();
	node operator--(int);

	// Equality / inequality.
	bool operator==(const node& rhs);
	bool operator!=(const node& rhs);

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
