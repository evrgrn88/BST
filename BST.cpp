#include <iostream>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <vector>
#include <ctime>
#include "BST.h"

using namespace std;

template <typename T>
BST<T>::BST()
{
    root = NULL;
}

template <typename T>
void BST<T>::MainMenu(short type)
{
    while (true)
    {
        system("cls");


		if (type == 1)
			cout << "���: ����� �����\n";
		else if (type == 2)
			cout << "���: ����� � ��������� ������\n";
		else if (type == 3)
			cout << "���: ������\n";

        short choice;
        cout << endl <<
			
			"��������:\n" <<
			"---------------------------------------------\n" <<
			"1. ������� ����� ������.\n" <<
			"2. ������� �������� �� �������.\n" <<
			"3. �������� ����� ��������� ������.\n" <<
			"4. �������� ������.\n" <<
			"5. ��������� ������ �� �������.\n" <<
			"6. ������ �������.\n" <<
			"7. �������� ����� �������.\n" <<
			"8. ������� �������.\n" <<
			"9. ������������ ��������.\n" <<
			"10. ����� Post-order (Lt -> Rt -> t).\n" <<
			"11. ���������� ��� ���������.\n" <<
			"12. ������������� ������.\n" <<
			"13. ��������� ������������������ ������.\n" <<
			"14. ����������� ����������.\n" <<
			"15. ���������� �������.\n" <<
			"16. ���������� ���������.\n\n" <<


			
			"0. �����.\n" <<

			"\n\n�������� ��������: ";

        cin >> choice;
        cout << endl;

		switch (choice)
		{
		case 1:
			FillTree();
			cout << endl;
			DrawTree(root, 0);
			break;

		case 2:
			PrintInOrder();
			cout << endl;
			DrawTree(root, 0);
			break;

		case 3:
			ShowSize();
			break;

		case 4:
			ClearTree(root);
			break;

		case 5:
			EmptyCheck(root);
			break;

		case 6:
			T searchKey;

			cout << "\n�����: ";
			cin >> searchKey;
			cout << endl;

			FindKeyHelper(searchKey);
			break;

		case 7:
			AddNewLeaf();
			cout << endl;
			DrawTree(root, 0);
			break;

		case 8:
			T deleteKey;

			cout << "������� ����: ";
			cin >> deleteKey;

			DeleteLeaf(deleteKey);
			cout << endl;
			DrawTree(root, 0);
			break;

		case 9:
			IteratorMenu();
			break;


		case 10:
			PrintPostOrder(root);
			cout << endl;
			DrawTree(root, 0);
			break;

		case 11:		
			MergePrepare();
			cout << endl;
			DrawTree(root, 0);
			break;
		
		case 12:
			unsigned int treeSize;

			cout << "\n������� ����� ���������: \n";

			cin >> treeSize;

			if (type == 3 && treeSize > 26)
			{
				cout << "\n��� ����������� ���� ������ ������ ������ ��������� 26 ���������� (����). ������� ����� ������: \n";
				cin >> treeSize;
			}

			cout << endl;

			GenerateTree(treeSize, type);
			cout << endl;
			DrawTree(root, 0);

			break;

		case 13:
			TestTree(type);
			break;
		
		case 14:
			BubbleSort(type);
			break;

		case 15:
			SelectionSort(type);
			break;

		case 16:
			InsertionSort(type);
			break;

		case 0:
			return;
			break;

		
		}

		cout << endl << endl;
		system("pause");
				
    }
}

template <typename T>
void BST<T>::IteratorMenu()
{
	if (root != NULL)
	{
		// ������ ��� ��������������� ������������������ ��-��� 
		// ��� ����������������� �������� �� ���������
		vector<T> SortedKeys; 
		short ch;
		
		SortedKeys = SortInOrder(root);
		iterator = SortedKeys.begin();
		
		while (true)
		{
			system("cls");

			cout << endl <<
				"1. ���������� �������� �� ������ ������.\n" <<
				"2. ��������� ����� ������.\n" <<
				"3. ������� �������.\n" <<
				"4. ��������� �� ����� �������.\n" <<
				"5. ���������� �� ����� �������.\n" <<

				"\n6. ���������� ����.\n"

				"\n\n�������� ��������: ";

			cin >> ch;
			cout << endl;

			switch (ch)
			{
			case 1:
				iterator = SortedKeys.begin();

				while (*iterator != root->key)
				{
					iterator++;
				}

				cout << "��������� �� ������ ������...\n����: " << *iterator << endl;

				break;

			case 2:
				iterator = SortedKeys.end();

				cout << "��������� �� ����� ������...\n����: " << *--iterator << endl;

				break;

			case 3:
				cout << "������� �������.\n����: " << *iterator << endl;
								
				break;
				
			case 4:
				iterator++;

				if (iterator != SortedKeys.end())
				{
					cout << "������� �� ��������� �� ����� ������� ������...\n����: " << *iterator << endl;
				}
				else
				{
					cout << "���� �����������!\n";
					--iterator;
				}

				break;

			case 5:
				if (iterator != SortedKeys.begin())
				{
					iterator--;
					cout << "������� �� ���������� �� ����� ������� ������...\n����: " << *iterator << endl;
				}
				else
				{
					cout << "���� �����������!\n";
				}

				break;

			case 6:
				return;
			}

			system("pause");
		}
	}
	else
	{
		cout << "������ �����.\n";
	}
}

template <typename T>
void BST<T>::FillTree()
{
    ClearTree(root);
    int treeSize;

    cout << "\n������� ����� ���������: \n";
    cin >> treeSize;
    cout << endl;

    for (int i = 0; i < treeSize; i++)
    {
        AddNewLeaf();
    }
}

// ��������� ����� ��� �������� ���������� �����
template <typename T>
void BST<T>::ShowSize()
{
    if (root != NULL)
    {
        // ���� ��� �������������� ��������
		stack<node*> s;
        int i = 0;
        node* Ptr = root;
        s.push(NULL);

        do
        {
            if (Ptr != NULL)
            {
                s.push(Ptr);
                Ptr = Ptr->left;
            }
            else
            {
                if (s.top() == NULL)
                {
                    break;
                }

                Ptr = s.top();
                i++;
                s.pop();
                Ptr = Ptr->right;
            }
        }
        while (true);

        cout << "���������� ���������: " << i;
    }
    else
    {
        cout << "\n������ �����.\n";
    }
}

// ������������ �������� ����� � ������ �������� ����� � ����������
template <typename T>
void BST<T>::ClearTree(node* Ptr)
{
    if (root != NULL)
    {
		while (Ptr->left != NULL)
		{
			DeleteLeaf(Ptr->left->key);
		}

		while (Ptr->right != NULL)
		{
			DeleteLeaf(Ptr->right->key);
		}

		DeleteLeaf(Ptr->key);
    }
}

template <typename T>
void BST<T>::EmptyCheck(node* Ptr)
{
    if (Ptr == NULL)
    {
        cout << "\n������ �����.\n";
    }
    else
    {
        cout << "\n������ �� �����.\n";
    }

    cout << endl;
}

// ����� ��������
template <typename T>
typename BST<T>::search BST<T>::FindKey(T key)
{
	search result;
	counter = 0;

	result.nodeptr = root;
	result.parent = NULL;
	result.isLeft = true;
		
	while (result.nodeptr != NULL)
	{
		counter++; // ������� ������������� ����� ��� ������������

		if (key == result.nodeptr->key)
		{			
			return result;
		}

		else if (key > result.nodeptr->key)
		{
			result.parent = result.nodeptr;
			result.nodeptr = result.nodeptr->right;
			result.isLeft = false;
		}
		else if (key < result.nodeptr->key)
		{
			result.parent = result.nodeptr;
			result.nodeptr = result.nodeptr->left;
			result.isLeft = true;
		}
	}

	return result;
}

template<typename T>
void BST<T>::FindKeyHelper(T searchKey)
{
	if (root != NULL)
	{
		search result = FindKey(searchKey);
		
		if (result.nodeptr == NULL)
			cout << "\n������� �� ������\n";
		else if (result.nodeptr->key == searchKey)
			cout << "\n������� ������\n";
	}
	else
		cout << "\n������ �����.\n";
}

template <typename T>
typename BST<T>::node* BST<T>::CreateLeaf(T key)
{
	node* n = new node;

    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

template <typename T>
bool BST<T>::AddLeaf(T key, node* Ptr)
{
	counter = 0;

	if (root == NULL)
    {
		counter++;
		root = CreateLeaf(key);
    }
    else
    {
		counter++;
		
		while (Ptr != NULL)
        {
            if (key == Ptr->key)
            {
				counter = 0;
				return true;
            }
            else
            {				
				if (key > Ptr->key)
                {
					counter++;
					
					if (Ptr->right != NULL)
                    {
						Ptr = Ptr->right;
                    }
                    else
                    {
						Ptr->right = CreateLeaf(key);
                        break;
                    }
                }
                else if (key < Ptr->key)
                {
					counter++;
					
					if (Ptr->left != NULL)
                    {
                        Ptr = Ptr->left;
                    }
                    else
                    {
                        Ptr->left = CreateLeaf(key);
                        break;
                    }
                }
            }
        }
    }
	return false;
}

// ���������� ���� �������
template <typename T>
void BST<T>::AddNewLeaf()
{
    T newKey;
	bool exists;
    
	do
	{
		cout << "\n������� ����: \n";
		cin >> newKey;
		exists = AddLeaf(newKey, root);

		if (exists)
			cout << "\n������� ��� ����������!";
	}
	while (exists); // �������� �� ������������� ����
	
    cout << endl;
}

// �������� ����
template <typename T>
void BST<T>::DeleteLeaf(T key)
{
    if (root != NULL)
    {		
		// ����� ���� ��� ��������
		search result = FindKey(key);

		node* Child = NULL;
		node* ParentReplacement = NULL;
		node* NodeReplacement = NULL;

		if (result.nodeptr == NULL)
		{
			cout << "\n������� �� ������\n";
			return;
		}

		if (result.nodeptr->key == key)
        {
			counter++;

			if (result.nodeptr->left == NULL && result.nodeptr->right == NULL) // 0 ��������
            {
                if (result.parent == NULL) // ���� �������� ��������
                {
                    root = NULL;
                }
                else
                {
                    delete result.nodeptr;

                    if (result.isLeft)
                    {
						result.parent->left = NULL;
                    }
                    else
                    {
						result.parent->right = NULL;
                    }
                }
				return;
            }

            if (result.nodeptr->left == NULL || result.nodeptr->right == NULL) // 1 �������
            {
				counter++;

				if (result.nodeptr->left != NULL)
                {
                    Child = result.nodeptr->left;
                }
                else
                {
                    Child = result.nodeptr->right;
                }

                if (result.parent == NULL) // ���� �������� ��������
                {
                    delete result.nodeptr;
					result.nodeptr = NULL;
                    root = Child;
                }
                else // �������� � ���������� ��������
                {
                    if (result.isLeft)
                    {
						result.parent->left = Child;
                    }
                    else
                    {
						result.parent->right = Child;
                    }

                    delete result.nodeptr;
					result.nodeptr = NULL;
                }

				return;
            }

            if (result.nodeptr->left != NULL && result.nodeptr->right != NULL) // 2 �������
            {
                // ����� ����������� ���� (����������� �����)
                ParentReplacement = result.nodeptr;
                NodeReplacement = result.nodeptr->left;
				result.isLeft = true; // ���������� ���� �����

                while (NodeReplacement->right != NULL)
                {
					counter++;
					ParentReplacement = NodeReplacement;
                    NodeReplacement = NodeReplacement->right;
					result.isLeft = 0; // ���������� ���� ������
                }

				result.nodeptr->key = NodeReplacement->key; // ����������� ������

                if (result.isLeft)
                {
					result.nodeptr->left = NodeReplacement->left;
                }
                else
                {
                    ParentReplacement->right = NodeReplacement->left;
                }

				counter++;
                return;
            }
        }
    }
    else
    {
        cout << "\n������ �����.\n";
    }
}

// ��������� ���������� � ������� � ������
template <typename T>
vector<T> BST<T>::SortInOrder(node* Ptr)
{	
	{
		stack<node*> s;
		vector<T> v;

		s.push(NULL);

		do
		{
			if (Ptr != NULL)
			{
				s.push(Ptr);
				Ptr = Ptr->left;
			}
			else
			{
				if (s.top() == NULL)
				{
					return v;
				}

				Ptr = s.top();
				v.push_back(Ptr->key);
				s.pop();
				Ptr = Ptr->right;
			}
		} while (true);
	}
}

template <typename T>
void BST<T>::PrintInOrder()
{
    if (root != NULL)
    {	
		vector<T> SortedKeys = SortInOrder(root);
		
		cout << "����� ��������� in-order (Lt -> T -> Rt):\n";
		
		for (auto i : SortedKeys)
		{
			cout << i << " ";
		}
    }
    else
    {
        cout << "\n������ �����.\n";
    }
}

// ����������� �����
template <typename T>
void BST<T>::PrintPostOrder(node* Ptr)
{
	if (root != NULL)
	{
		cout << "����� ��������� post-order (Lt -> Rt -> T):\n";

		stack<node*> s;

		do
		{
			while (Ptr != NULL)
			{
				if (Ptr->right != NULL)
				{
					s.push(Ptr->right);
				}

				s.push(Ptr);
				Ptr = Ptr->left;
			}

			Ptr = s.top();
			s.pop();

			if (!s.empty())
			{
				if (Ptr->right != NULL && s.top() == Ptr->right)
				{
					s.pop();
					s.push(Ptr);
					Ptr = Ptr->right;
				}
				else
				{
					cout << Ptr->key << " ";
					Ptr = NULL;
				}
			}
			else
			{
				cout << Ptr->key << " ";
			}
		} while (!s.empty());
	}
	else
	{
		cout << "\n������ �����.\n";
	}
}

template<typename T>
void BST<T>::MergePrepare()
{
	if (root != NULL)
	{
		T mergeKey;

		cout << "������� ����-�������� ����������� ��� �����������: ";
		cin >> mergeKey;

		node* Ptr;
		search result = FindKey(mergeKey); // ����� ����-�������� ��� ����������� �����������

		if (result.nodeptr != NULL)
		{
			if (result.parent == NULL) // �������� - ������
			{
				while (result.nodeptr->right != NULL)
				{
					Ptr = MergeSubtree(result.nodeptr->right, false);

					if (Ptr == result.nodeptr->right)
						result.nodeptr->right = Ptr->right;

					Ptr->right = NULL;
					Ptr->left = root;
					root = Ptr;
				}
			}
			else if (result.isLeft == true) // ���� - ����� �� ��������
			{
				while (result.nodeptr->right != NULL)
				{
					Ptr = MergeSubtree(result.nodeptr, true);
					Ptr->left = result.nodeptr;
					result.parent->left = Ptr;
					result.parent = result.parent->left;
				}
			}
			else if (result.isLeft == false) // ���� - ������ �� ��������
			{
				while (result.nodeptr->left != NULL)
				{
					Ptr = MergeSubtree(result.nodeptr, false);
					Ptr->right = result.nodeptr;
					result.parent->right = Ptr;
					result.parent = result.parent->right;
				}
			}
		}
	}
}
		
template<typename T>
typename BST<T>::node* BST<T>::MergeSubtree(node* Ptr, bool isLeft)
{
	node* temp;

	if (isLeft)
	{
		if (Ptr->right != NULL)
		{
			temp = MergeSubtree(Ptr->right, true);

			if (Ptr->right == temp)
				Ptr->right = temp->left;

			return temp;
		}
		else
		{
			return Ptr;
		}
	}
	else
	{
		if (Ptr->left != NULL)
		{
			temp = MergeSubtree(Ptr->left, false);

			if (Ptr->left == temp)
				Ptr->left = temp->right;

			return temp;
		}
		else
		{
			return Ptr;
		}
	}
	
	return Ptr;
}

// ����������� ��������� ������
template<typename T>
void BST<T>::DrawTree(node* Ptr, int space)
{
	if (root != NULL)
	{
		if (Ptr == NULL)
			return;
		
		// ��������� ����� ��������
		space += 5;

		// ��������� ������ ������� ������
		DrawTree(Ptr->right, space);

		// ������ �������� ���� ����� �������
		cout << endl;

		for (int i = 5; i < space; i++)
			cout << " ";
		
		cout << Ptr->key;

		// ��������� ����� �������
		DrawTree(Ptr->left, space);

		cout << endl << endl;
	}
	else
	{
		cout << "\n������ �����.\n";
	}
}

template<typename T>
unsigned int BST<T>::GenerateTree(unsigned int size, short type)
{
	unsigned int insertCounter = 0; // ������� ��� ������������
	
	ClearTree(root);

	T key = NULL;
	bool exists;

	srand((unsigned int)time(NULL)); // ������������� ���������� ��������� �������� (����)

	for (unsigned int i = 0; i < size; i++)
	{
		do
		{
			if (type == 3) // ������ �� a �� z;
				key = (rand() % 26) + 'a';
			else if (type == 2) // ����� � ��������� ������
				key = (T)(rand()) / (rand());
			else if (type == 1) // ����� �����
				key = ((rand() + 1) * (rand() + 1) / (rand() + 1));

			exists = AddLeaf(key, root);
		} while (exists);

		insertCounter += counter;
	}

	return insertCounter;
}

// ������������ ���������
template<typename T>
void BST<T>::TestTree(short type)
{	
	bool exists;
	
	unsigned int size;
	unsigned int searchCounter = 0;
	unsigned int insertCounter = 0;
	unsigned int deleteCounter = 0;

	vector<T> v; // ������ ��� �������������� ��������

	srand((unsigned int)time(NULL)); // ������������� ���������� ��������� �������� (����)

	if (type != 3)
	{
		// ���������������� ��������� �������� �� 10 �� 100000 ���������, � ����� 10,
		// ������� ������
		for (size = 10; size < 100001; size *= 10) 
		{
			cout << "\n\n������: " << size << " ���������.\n";
			
			cout << "\n������� ����� ���������� �����:\n";

			counter = 0;

			// ��������� ������ � ���������� ������������� �����
			insertCounter = GenerateTree(size, type);

			cout << "�������: " << insertCounter / size << endl;

			// ��������� ��������� ������ � ������ �� �����������
			v = SortInOrder(root);

			counter = 0;
			
			// ���������������� ����� ���� ����� � ��������� ����������
			for (auto i : v)
			{
				FindKey(i);
				searchCounter += counter;
			}

			cout << "�����: " << searchCounter / size << endl;
			
			// �������� ���� ��������� ������ ��������� ������� � ���������
			// ������������� �����
			for (unsigned int i = 0; i < size; i++)
			{
				// ����� ���������� �������� �������
				unsigned int key = (rand() % v.size());
				
				DeleteLeaf(v.at(key)); // �������� �������� ������
				v.erase(v.begin() + key); // �������� �������� �������
				deleteCounter += counter;
			}

			cout << "��������: " << deleteCounter / size << endl << endl;
		}

		cout << endl;

		searchCounter = 0;
		insertCounter = 0;
		deleteCounter = 0;

		// ������ ������ (�� ����� - ������������� ������)
		for (size = 10; size < 100001; size *= 10)
		{
			cout << "\n\n������: " << size << " ���������.\n";

			cout << "\n������� ����� ���������� ����� (������ ������):\n";

			GenerateTree(size, type);

			// �������� �������������� ������� ��������� ��������
			v = SortInOrder(root);

			ClearTree(root);

			counter = 0;

			// ��������� ������ � ��������� ������������� �����
			for (auto i = v.rbegin(); i != v.rend(); i++)
			{
				do
					exists = AddLeaf(*i, root);
				while (exists);

				insertCounter += counter;
			}

			cout << "�������: " << insertCounter / size << endl;

			counter = 0;

			// ���������������� ����� ���� ����� � ��������� ����������
			for (auto i = v.rbegin(); i != v.rend(); i++)
			{
				FindKey(*i);
				searchCounter += counter;
			}

			cout << "�����: " << searchCounter / size << endl;

			// �������� ���� ��������� ������ ��������� ������� � ���������
			// ������������� �����
			for (unsigned int i = 0; i < size; i++)
			{
				// ����� ���������� �������� �������
				unsigned int key = (rand() % v.size());

				DeleteLeaf(v.at(key)); // �������� �������� ������
				v.erase(v.begin() + key); // �������� �������� �������
				deleteCounter += counter;
			}

			cout << "��������: " << deleteCounter / size << endl << endl;
		}

		cout << endl;
	}
	else
	{
		cout << "\n��� ����������� ���� ������ ������ ��������� 26 ���������� (����).\n";

		size = 26;
		
		cout << "\n\n������: " << size << " ���������.\n";
		cout << "\n������� ����� ���������� �����:\n";

		counter = 0;

		insertCounter = GenerateTree(size, type);

		cout << "�������: " << insertCounter / size << endl;

		v = SortInOrder(root);

		counter = 0;

		for (auto i : v)
		{
			FindKey(i);
			searchCounter += counter;
		}

		cout << "�����: " << searchCounter / size << endl;

		for (unsigned int i = 0; i < size; i++)
		{
			unsigned int key = (rand() % v.size());

			DeleteLeaf(v.at(key));

			v.erase(v.begin() + key);

			deleteCounter += counter;
		}

		cout << "��������: " << deleteCounter / size << endl;
		cout << endl;

		// ������������ ������������ ������
		cout << "\n��� ����������� ���� ������ ������ ��������� 26 ���������� (����).\n";

		size = 26;

		cout << "\n\n������: " << size << " ���������.\n";
		cout << "\n������� ����� ���������� ����� (������ ������):\n";

		GenerateTree(size, type);

		v = SortInOrder(root);

		ClearTree(root);

		counter = 0;

		// ��������� ������ � ��������� ������������� �����
		for (auto i = v.rbegin(); i != v.rend(); i++)
		{
			do
				exists = AddLeaf(*i, root);
			while (exists);

			insertCounter += counter;
		}

		cout << "�������: " << insertCounter / size << endl;

		for (auto i : v)
		{
			FindKey(i);
			searchCounter += counter;
		}

		cout << "�����: " << searchCounter / size << endl;

		for (unsigned int i = 0; i < size; i++)
		{
			unsigned int key = (rand() % v.size());

			DeleteLeaf(v.at(key));

			v.erase(v.begin() + key);

			deleteCounter += counter;
		}

		cout << "��������: " << deleteCounter / size << endl;
		cout << endl;
	}
}

template<typename T>
bool BST<T>::LinearSearch(vector<T> v, T key)
{
	for (auto i : v)
		if (i == key)
			return true;

	return false;
}

template<typename T>
vector<T> BST<T>::GenerateVector(short type)
{
	vector<T> v;
	T key = NULL;
	unsigned int size;
	bool exists;

	srand((unsigned int)time(NULL)); // ������������� ���������� ��������� �������� (����)

	cout << "\n������� ������ �������: ";
	cin >> size;

	for (unsigned int i = 0; i < size; i++)
	{
		do
		{
			if (type == 3) // ������ �� a �� z;
				key = (rand() % 26) + 'a';
			else if (type == 2) // ����� � ��������� ������
				key = (T)(rand()) / (rand());
			else if (type == 1) // ����� �����
				key = ((rand() + 1) * (rand() + 1) / (rand() + 1));

			exists = LinearSearch(v, key);
		} while (exists);

		v.push_back(key);
	}

	return v;
}

template<typename T>
vector<T> BST<T>::EnterVector()
{
	vector<T> vec;
	T key;
	
	int size;
	
	cout << "������� ������: ";
	cin >> size;
		
	for (int i = 0; i < size; i++)
	{
		cin >> key;
		vec.push_back(key);
	}
			
	return vec;
}

template<typename T>
vector<T> BST<T>::BubbleSort(short type, vector<T> vec)
{	
	//vector<T> vec = EnterVector();
	//vector<T> vec = GenerateVector(type);

	int size = vec.size();
	bool swaps;
	T left, right;

	for (auto i : vec)
		cout << i << " ";

	cout << endl << endl;

	system("pause");

	do
	{
		swaps = false;

		for (int i = 0; i < size; i++)
		{
			if (vec.at(i) != vec.back())
			{
				left = vec.at(i);
				right = vec.at(++i);

				if (left > right)
				{
					vec.at(i) = left;
					vec.at(--i) = right;
					swaps = true;

					for (auto i : vec)
						cout << i << " ";

					cout << endl;
				}
				else
					i--;
			}
		}
	} while (swaps);
}

template<typename T>
vector<T> BST<T>::SelectionSort(short type, vector<T> vec)
{
	int hold, step;
	T temp;

	//vector<T> vec = EnterVector();
	//vector<T> vec = GenerateVector(type);
	int size = vec.size();

	cout << "\n��������������� ������:\n";

	for (auto i : vec)
		cout << i << " ";

	cout << endl << endl;

	system("pause");
	
	for (int i = 0; i < size;)
	{
		hold = i;
		step = i;

		while (vec.at(step) != vec.back())
		{
			step++;

			if (vec.at(step) < vec.at(hold))
				hold = step;			
		}

		temp = vec.at(hold);
		vec.at(hold) = vec.at(i);
		vec.at(i) = temp;

		cout << endl << "[ " << ++i << " ]\n";
		
		for (auto i : vec)
			cout << i << " ";

		cout << endl;
	}
}

template<typename T>
vector<T> BST<T>::InsertionSort(short type, vector<T> vec)
{
	T temp;
	
	//vector<T> vec = EnterVector();
	//vector<T> vec = GenerateVector(type);
	int size = vec.size();

	cout << "\n��������������� ������:\n";

	for (auto i : vec)
		cout << i << " ";

	cout << endl << endl;

	system("pause");

	for (int i = 1; i < size; i++)
	{
		typename vector<T>::iterator it = vec.begin();
		//int j = 0;

		while (*it != i)
		{
			if (vec.at(i) < *it)
			{
				//vec.insert(it);
			}
			
			it++;
		}
		//system("pause");
	}
}

template <typename T>
BST<T>::~BST()
{}