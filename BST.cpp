/*
TODO:

Объединение двух поддеревьев (рекурсивно)
SortPostOrder, вывод в вектор


Вывод структуры на экран

Опрос числа просмотренных нод (в каждую операцию?)

*/



#include <iostream>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <vector>
#include "BST.h"

using namespace std;

template <typename T>
BST<T>::BST()
{
    root = NULL;
}

template <typename T>
void BST<T>::MainMenu()
{
	while (true)
	{
		system("cls");

		short choice;
		cout << endl <<
			"1. Создать новое дерево.\n" <<
			"2. Вывести элементы по порядку.\n" <<
			"3. Показать число элементов дерева.\n" <<
			"4. Очистить дерево.\n" <<
			"5. Проверить дерево на пустоту.\n" <<
			"6. Искать элемент.\n" <<
			"7. Добавить новый элемент.\n" <<
			"8. Удалить элемент.\n" <<
			"9. Использовать итератор.\n" <<
			"10. Обход Post-order (Lt -> Rt -> t).\n" <<
			"11. Объединить два поддерева.\n" <<
			"12. Сгенерировать тестовое дерево.\n" <<


			"\n\nВыберите операцию: ";

		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 1:
				FillTree();
				break;

			case 2:
				PrintInOrder();
				break;

			case 3:
				ShowSize();
				break;

			case 4:
				ClearTree(root);
				break;

<<<<<<< HEAD
			case 5:
				EmptyCheck(root);
				break;
=======
			FindByKey(search, root);
>>>>>>> parent of ec39690... wip MergeSubtrees

			case 6:
				T search;

				cout << "\nПоиск: ";
				cin >> search;
				cout << endl;

				FindByKey(search);// , root);
				break;

			case 7:
				AddNewLeaf();
				break;

			case 8:
				T deleteKey;

				cout << "Введите ключ: ";
				cin >> deleteKey;

				DeleteLeaf(deleteKey);
				break;

			case 9:
				IteratorMenu();
				break;


<<<<<<< HEAD
			case 10:
				PrintPostOrder(root);
				break;

			case 11:
			{
				T mergeKey;

				cout << "Введите ключ-родитель поддеревьев для объединения: ";
				cin >> mergeKey;

				MergeSubtrees(mergeKey);
				break;
			}

			case 12:
				GenerateTree();
				break;
=======
		case 11:
		{
			node* Ptr = NULL;

			for (iterator = SortedKeys.begin(); iterator < SortedKeys.end(); iterator++)
			{
				Ptr = *iterator;
				cout << Ptr->key << " ";
			}
>>>>>>> parent of ec39690... wip MergeSubtrees
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
<<<<<<< HEAD
		vector<node*> SortedKeys;
=======
>>>>>>> parent of ec39690... wip MergeSubtrees
		node* Ptr = NULL;
		short ch;
		
		SortInOrder(root);
		iterator = SortedKeys.begin();
		Ptr = *iterator;
		
		while (true)
		{
			system("cls");

			cout << endl <<
				"1. Установить итератор на корень дерева.\n" <<
				"2. Проверить конец дерева.\n" <<
				"3. Текущий элемент.\n" <<
				"4. Следующий по ключу элемент.\n" <<
				"5. Предыдущий по ключу элемент.\n" <<

				"\n6. Предыдущее меню.\n"

				"\n\nВыберите операцию: ";

			cin >> ch;
			cout << endl;

			switch (ch)
			{
			case 1:
				iterator = SortedKeys.begin();
				Ptr = *iterator;

				while (Ptr->key != root->key)
				{
					iterator++;
					Ptr = *iterator;
				}

				cout << "Установка на корень дерева...\nКлюч: " << Ptr->key << endl;

				break;

			case 2:
				iterator = SortedKeys.end();
				Ptr = *--iterator;
				cout << "Установка на конец дерева...\nКлюч: " << Ptr->key << endl;

				break;

			case 3:
				cout << "Текущий элемент.\nКлюч: " << Ptr->key << endl;
								
				break;
				
			case 4:
				iterator++;

				if (iterator != SortedKeys.end())
				{
					Ptr = *iterator;
					cout << "Переход на следующий по ключу элемент дерева...\nКлюч: " << Ptr->key << endl;
				}
				else
				{
					cout << "Ключ отсутствует!\n";
					Ptr = *--iterator;
				}

				break;

			case 5:
				if (iterator != SortedKeys.begin())
				{
					iterator--;
					Ptr = *iterator;
					cout << "Переход на предыдущий по ключу элемент дерева...\nКлюч: " << Ptr->key << endl;
				}
				else
				{
					cout << "Ключ отсутствует!\n";
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
		cout << "Дерево пусто.\n";
	}
}

template <typename T>
void BST<T>::FillTree()
{
    ClearTree(root);
    int treeSize;

    cout << "\nВведите число элементов: \n";
    cin >> treeSize;
    cout << endl;

    for (int i = 0; i < treeSize; i++)
    {
        AddNewLeaf();
    }
}

template <typename T>
void BST<T>::ShowSize()
{
    if (root != NULL)
    {
        stack<node*> s;
        T i = 0;
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

        cout << "Количество элементов: " << i;
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }
}

template <typename T>
void BST<T>::ClearTree(node* Ptr)
{
    if (root != NULL)
    {
        while (Ptr != NULL)
        {
			/*if (Ptr->left != NULL)
			{
				Ptr->left = DeleteLeaf
			}*/
			
			
			cout << "Удаление элемента " << Ptr->key << endl;
            Ptr = DeleteLeaf(Ptr->key);
        }

        cout << "\nДерево очищено.\n";
    }
    else
    {
        cout << "Дерево пусто.\n";
    }
}

template <typename T>
void BST<T>::EmptyCheck(node* Ptr)
{
    if (Ptr == NULL)
    {
        cout << "\nДерево пусто.\n";
    }
    else
    {
        cout << "\nДерево НЕ пусто.\n";
    }

    cout << endl;
}

template <typename T>
<<<<<<< HEAD
typename BST<T>::node* BST<T>::FindByKey(T key)
{	
	node* Ptr = NULL;

	if (root != NULL)
=======
void BST<T>::FindByKey(T key, node* Ptr)
{
    if (root != NULL)
>>>>>>> parent of ec39690... wip MergeSubtrees
    {
        while (Ptr != NULL)
        {
            if (Ptr->key == key)
            {
                break;
            }

            if (key > Ptr->key)
            {
                Ptr = Ptr->right;
            }
            else if (key < Ptr->key)
            {
                Ptr = Ptr->left;
            }
        }

        if (Ptr == NULL)
        {
            cout << "\nЭлемент НЕ найден\n";
            return;
        }

        if (Ptr->key == key)
        {
            cout << "\nЭлемент найден\n";
        }
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }

	return Ptr;
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
void BST<T>::AddLeaf(T key, node* Ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else
    {
        while (Ptr != NULL)
        {
            if (key == Ptr->key)
            {
                cout << "\nЭлемент уже существует!\nВведите новое значение: ";
                cin >> key;
                Ptr = root;
            }
            else
            {
                if (key > Ptr->key)
                {
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
}

template <typename T>
void BST<T>::AddNewLeaf()
{
    T newKey;
    cout << "\nВведите ключ: \n";
    cin >> newKey;
    AddLeaf(newKey, root);
    cout << endl;
}

template <typename T>
typename BST<T>::node* BST<T>::DeleteLeaf(T key, node* Ptr)
{
    if (root != NULL)
    {
        //node* Ptr = root;
        node* Parent = NULL;
        node* Child = NULL;
        node* ParentReplacement = NULL;
        node* NodeReplacement = NULL;

        bool isLeft; // 1 for left. 0 for right

        while (Ptr != NULL) // Check if the key is present
        {
            if (key == Ptr->key)
            {
                break;
            }

            if (key > Ptr->key)
            {
                Parent = Ptr;
                isLeft = false; // Right
                Ptr = Ptr->right;
            }
            else if (key < Ptr->key)
            {
                Parent = Ptr;
                isLeft = true; // Left
                Ptr = Ptr->left;
            }
        }

        if (Ptr == NULL)
        {
            cout << "\nЭлемент НЕ найден\n";
            return Ptr;
        }

        if (Ptr->key == key)
        {
            if (Ptr->left == NULL && Ptr->right == NULL) // 0 children
            {
                if (Parent == NULL) // Node is a root
                {
                    delete root;
					//Ptr = NULL;
                    root = NULL;

					return root;
                }
                else
                {
                    /*delete Ptr;
					Ptr = NULL;*/

                    if (isLeft)
                    {
						delete Parent->left;
                        Parent->left = NULL;
                    }
                    else
                    {
						delete Parent->right;
						Parent->right = NULL;
                    }
                }

                cout << "...готово.\n\n";
				return Parent;
            }

            if (Ptr->left == NULL || Ptr->right == NULL) // 1 child
            {
                if (Ptr->left != NULL)
                {
                    Child = Ptr->left;
                }
                else
                {
                    Child = Ptr->right;
                }

                if (Parent == NULL) // Root node is being deleted
                {
                    delete root;
					//Ptr = NULL;
                    root = Child;
                }
                else // Deleting node, parent adopting node children
                {
                    if (isLeft)
                    {
						delete Parent->left;
						Parent->left = Child;
                    }
                    else
                    {
						delete Parent->right;
						Parent->right = Child;
                    }

                    /*delete Ptr;
					Ptr = NULL;*/
                }

                cout << "...готово.\n\n";
				return Child;
            }

            if (Ptr->left != NULL && Ptr->right != NULL) // 2 children
            {
                // Finding replacement (highest node less than node to delete)
                ParentReplacement = Ptr;
                NodeReplacement = Ptr->left;
                isLeft = true; // NodeReplacement is left child of parent

                while (NodeReplacement->right != NULL)
                {
                    ParentReplacement = NodeReplacement;
                    NodeReplacement = NodeReplacement->right;
                    isLeft = false; // NodeReplacement is right child of parent
                }

				
				

				//Ptr->key = NodeReplacement->key; // Copying data

                if (isLeft) // NodeReplacement is left child of Ptr.
                {
					if (Parent != NULL)
					{
						if (Ptr == Parent->left)
						{
							delete Parent->left;
							Parent->left = NodeReplacement;
							//Ptr = Parent->left;
						}
						else
						{
							delete Parent->right;
							Parent->right = NodeReplacement;
						}
					}
					
					Ptr->left = NodeReplacement->left;
                }
                else // NodeReplacement is right grandchild of Ptr->left
                {
					if (Parent != NULL)
					{
						if (Ptr == Parent->left)
						{
							Ptr = NodeReplacement;
							
							while (Ptr->left != NULL)
							{
								Ptr = Ptr->left;
							}
							
							delete Parent->left;
							Parent->left = NodeReplacement;
							Ptr->left
						}
						else
						{
							delete Parent->right;
							Parent->right = NodeReplacement;
						}
					}
					
					ParentReplacement->right = NodeReplacement->left;
                }

                cout << "...готово.\n\n";
				return Parent;
            }
        }
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }

	return root;
}

template <typename T>
<<<<<<< HEAD
vector<typename BST<T>::node*> BST<T>::SortInOrder(node* Ptr)
{	
	{
		stack<node*> s;
		vector<node*> v;
=======
void BST<T>::SortInOrder(node* Ptr)
{
	if (!SortedKeys.empty())
	{
		SortedKeys.clear();
	}
	else
	{
		stack<node*> s;
>>>>>>> parent of ec39690... wip MergeSubtrees
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
					return;
				}

				Ptr = s.top();
<<<<<<< HEAD
				v.push_back(Ptr);
=======
				SortedKeys.push_back(Ptr);
>>>>>>> parent of ec39690... wip MergeSubtrees
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
		node* Ptr = NULL;
		
		cout << "Вывод элементов in-order (Lt -> T -> Rt):\n";

		SortInOrder(root);
		
		for (iterator = SortedKeys.begin(); iterator != SortedKeys.end(); iterator++)
		{
			Ptr = *iterator;
			cout << Ptr->key << " ";
		}
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }
}

<<<<<<< HEAD
template<typename T>
void BST<T>::MergeSubtrees(T key)
{
	if (root != NULL)
	{
		vector<node*> v, v_merged;
		node* Ptr = FindByKey(key);

		if (Ptr->left != NULL)
		{
			v_merged = SortInOrder(Ptr->left);
		}

		if (Ptr->right != NULL)
		{
			v = SortInOrder(Ptr->right);
		}

		v_merged.push_back(Ptr);
		v_merged.insert(v_merged.end(), v.begin(), v.end());

		/*for (auto i : v_merged)
		{
			DeleteLeaf(i->key);
		}*/

		ClearTree(Ptr);
	}
}

template<typename T>
void BST<T>::GenerateTree()
{
	ClearTree(root);

	int arr[11] = { 22, 7, 83, 6, 12, 33, 90, 4, 11, 1, 3 };

	for (int i = 0; i < 11; i++)
		AddLeaf(arr[i], root);

	cout << "...сделано\n";
}

=======
>>>>>>> parent of ec39690... wip MergeSubtrees
template <typename T>
void BST<T>::PrintPostOrder(node* Ptr)
{
    if (root != NULL)
    {
        cout << "Вывод элементов post-order (Lt -> Rt -> T):\n";

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
        }
        while (!s.empty());
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }
}

/*
BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if(key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }

}

int BST::ReturnRootKey()
{
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void BST::PrintChildren(int key)
{
    node* Ptr = ReturnNode(key);

    if(Ptr !=NULL)
    {
        cout << "Parent node = " << Ptr->key << endl;

        Ptr->left == NULL ?
                    cout << "Left child = NULL\n" :
                    cout << "Left child = " << Ptr->left->key << endl;

        Ptr->right == NULL ?
                    cout << "Right child = NULL\n" :
                    cout << "Right child = " << Ptr->right->key << endl;

    }
    else
    {
        cout << "Key " << key << " is not in the tree\n";
    }
}

int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
    if(root == NULL)
    {
        cout << "Дерево пусто\n";
        return -1000;
    }
    else
    {
        if(Ptr->left != NULL)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        else
        {
            return Ptr->key;
        }
    }
}

void BST::RemoveNode(int key)
{
    return RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
    if(root != NULL)
    {
        if(root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if(key < parent->key && parent->left != NULL)
            {
                parent->left->key == key ?
                            RemoveMatch(parent, parent->left, true) :
                            RemoveNodePrivate(key, parent -> left);
            }
            else if(key > parent->key && parent->right != NULL)
            {
                parent->right->key == key ?
                            RemoveMatch(parent, parent->right, false) :
                            RemoveNodePrivate(key, parent -> right);
            }
            else
            {
                cout << "The key " << key << " was not found in the tree\n";
            }
        }
    }
    else
    {
        cout << "Дерево пусто\n";
    }
}

void BST::RemoveRootMatch()
{
    if(root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // 0-0 children
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }

        // 1-1 child
        else if(root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << "was deleted. " <<
                    "The new root contains key " << root->key << endl;
        }
        else if(root->right != NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << "was deleted. " <<
                    "The new root contains key " << root->key << endl;
        }

        // 2-2 Children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey <<
                    " was overwritten with key " << root->key << endl;
        }
    }
    else
    {
        cout << "Can not remove root. Дерево пусто\n";
    }
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
    if(root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // 0-0
        if(match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true ?
                        parent->left = NULL:
                        parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }

        // 1-1
        else if(match->left == NULL && match->right != NULL)
        {
            left == true ?
                        parent->left = match->right:
                        parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        else if(match->left != NULL && match->right == NULL)
        {
            left == true ?
                        parent->left = match->left:
                        parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }

        // 2-2
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "Can not remove match. Дерево пусто\n";

    }
}

// Post-order traversal
void BST::RemoveSubtree(node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->left != NULL)
        {
            RemoveSubtree(Ptr->left);
        }
        if(Ptr->right != NULL)
        {
            RemoveSubtree(Ptr->right);
        }
        cout << "Deleting the node containing key " << Ptr->key << endl;
        delete Ptr;
    }
}
*/

template <typename T>
BST<T>::~BST()
{

}
