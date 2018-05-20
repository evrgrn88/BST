/*
TODO:

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
			"12. test (DrawTree)\n" <<
			"13. Сгенерировать тестовое дерево.\n" <<
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

		case 5:
			EmptyCheck(root);
			break;

		case 6:
			T search;

			cout << "\nПоиск: ";
			cin >> search;
			cout << endl;

			FindByKey(search);

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


		case 10:
			PrintPostOrder(root);
			break;

		case 11:		
			MergePrepare();		
			break;
		
		case 12:
		{
			//vector<node*> test;

			//GenerateTree();
			//test.push_back(root);
			//test.push_back(root->left);
			//test.push_back(root->left->left);
			//test.push_back(root->left->right);
			//test.push_back(root->left->right->left);
			//test.push_back(root->right);
			//
			//cout << endl;

			//for (auto i : test)
			//	cout << i->key << " ";
			//cout << endl << endl;

			//node* Ptr = root->left->right;
			//
			//Ptr = root->left->left;

			//cout << endl << root->key << endl << root->left->key << endl << root->left->right->key << endl << endl;
			//			
			//for (auto i : test)
			//	cout << i->key << " ";
			//cout << endl << endl;

			DrawTree(root, 0);

			break;
		}

		case 13:
			GenerateTree();
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
		vector<T> SortedKeys;
		short ch;
		
		SortedKeys = SortInOrder(root);
		iterator = SortedKeys.begin();
		
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

				while (*iterator != root->key)
				{
					iterator++;
				}

				cout << "Установка на корень дерева...\nКлюч: " << *iterator << endl;

				break;

			case 2:
				iterator = SortedKeys.end();

				cout << "Установка на конец дерева...\nКлюч: " << *--iterator << endl;

				break;

			case 3:
				cout << "Текущий элемент.\nКлюч: " << *iterator << endl;
								
				break;
				
			case 4:
				iterator++;

				if (iterator != SortedKeys.end())
				{
					cout << "Переход на следующий по ключу элемент дерева...\nКлюч: " << *iterator << endl;
				}
				else
				{
					cout << "Ключ отсутствует!\n";
					--iterator;
				}

				break;

			case 5:
				if (iterator != SortedKeys.begin())
				{
					iterator--;
					cout << "Переход на предыдущий по ключу элемент дерева...\nКлюч: " << *iterator << endl;
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
		while (Ptr->left != NULL)
		{
			cout << "Удаление элемента " << Ptr->left->key << endl;
			DeleteLeaf(Ptr->left->key);
		}

		while (Ptr->right != NULL)
		{
			cout << "Удаление элемента " << Ptr->right->key << endl;
			DeleteLeaf(Ptr->right->key);
		}

		cout << "Удаление элемента " << Ptr->key << endl;
		DeleteLeaf(Ptr->key);

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
typename BST<T>::node* BST<T>::FindByKey(T key)
{
	if (root != NULL)
	{
		node* Parent = NULL;
		node* Ptr = root;

		while (Ptr != NULL) // Check if the key is present
		{
			if (key == Ptr->key)
			{
				break;
			}

			if (key > Ptr->key)
			{
				Parent = Ptr;
				Ptr = Ptr->right;
			}
			else if (key < Ptr->key)
			{
				Parent = Ptr;
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
			cout << "\nЭлемент найден\n";

			if (Parent != NULL)
				return Parent;
			else
			{
				return Ptr;
			}
		}

		return Ptr;
	}
	else
	{
		cout << "\nДерево пусто.\n";
		return root;
	}
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
void BST<T>::DeleteLeaf(T key)
{
    if (root != NULL)
    {
        node* Ptr = root;
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
            return;
        }

        if (Ptr->key == key)
        {
            if (Ptr->left == NULL && Ptr->right == NULL) // 0 children
            {
                if (Parent == NULL) // Node is a root
                {
                    root = NULL;
                }
                else
                {
                    delete Ptr;

                    if (isLeft)
                    {
                        Parent->left = NULL;
                    }
                    else
                    {
                        Parent->right = NULL;
                    }
                }

                cout << "...готово.\n\n";
                return;
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
                    delete Ptr;
					Ptr = NULL;
                    root = Child;
                }
                else // Deleting node, parent adopting node children
                {
                    if (isLeft)
                    {
                        Parent->left = Child;
                    }
                    else
                    {
                        Parent->right = Child;
                    }

                    delete Ptr;
					Ptr = NULL;
                }

                cout << "...готово.\n\n";
                return;
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
                    isLeft = 0; // NodeReplacement is right child of parent
                }

                Ptr->key = NodeReplacement->key; // Copying data

                if (isLeft) // NodeReplacement is left child of Ptr.
                {
                    Ptr->left = NodeReplacement->left;
                }
                else // NodeReplacement is right grandchild of Ptr->left
                {
                    ParentReplacement->right = NodeReplacement->left;
                }

                cout << "...готово.\n\n";
                return;
            }
        }
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }
}

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
		
		cout << "Вывод элементов in-order (Lt -> T -> Rt):\n";
		
		for (auto i : SortedKeys)
		{
			cout << i << " ";
		}
    }
    else
    {
        cout << "\nДерево пусто.\n";
    }
}

template<typename T>
void BST<T>::MergePrepare()
{
	if (root != NULL)
	{
		T mergeKey;

		cout << "Введите ключ-родитель поддеревьев для объединения: ";
		cin >> mergeKey;

		node* Ptr;
		node* Parent = FindByKey(mergeKey);

		if (Parent != NULL)
		{
			if (Parent->key != mergeKey)
			{
				if (Parent->left != NULL && Parent->left->key == mergeKey)
				{
					Ptr = Parent->left;

					while (Ptr->right != NULL)
					{
						MergeSubtree(Parent, Ptr, 1);
						Parent = Parent->left;
					}
				}

				if (Parent->right != NULL && Parent->right->key == mergeKey)
				{
					Ptr = Parent->right;

					while (Ptr->left != NULL)
					{
						MergeSubtree(Parent, Ptr, 0);
						Parent = Parent->right;
					}
				}
			}
			else
			{
				Ptr = Parent;
				
				while (Ptr->right != NULL)
				{
					MergeSubtree(Parent, Ptr->right, -1);
				}
			}
		}
	}
}
		
template<typename T>
typename BST<T>::node* BST<T>::MergeSubtree(node* Parent, node* Ptr, short isLeft)
{
	node* temp;

	if (isLeft == 1)
	{
		if (Ptr->right != NULL)
		{
			temp = MergeSubtree(Ptr, Ptr->right, 1);
			temp->left = Parent->left;
			Parent->left = temp;
		}
		else
		{
			Parent->right = Ptr->left;
			Ptr->left = NULL;
		}
	}

	if (isLeft == 0)
	{
		if (Ptr->left != NULL)
		{
			temp = MergeSubtree(Ptr, Ptr->left, 0);
			temp->right = Parent->right;
			Parent->right = temp;
		}
		else
		{
			Parent->left = Ptr->right;
			Ptr->right = NULL;
		}
	}

	if (isLeft == -1)
	{
		if (Ptr->left != NULL)
		{
			temp = MergeSubtree(Ptr, Ptr->left, -1);
			temp->left = root;
			root = temp;
		}
		else
		{
			if (Parent->right != NULL && Parent->right == Ptr)
			{
				temp = Parent->right;
				Parent->right = temp->right;
				temp->right = NULL;
				temp->left = root;
				root = temp;
			}
			else
			{
				Parent->left = Ptr->right;
				Ptr->right = NULL;
			}
		}
	}

	return Ptr;
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

template<typename T>
void BST<T>::DrawTree(node* Ptr, int space)
{
	if (root != NULL)
	{
		if (Ptr == NULL)
			return;
		
		// Increase distance between levels
		space += 5;

		// Process right child first
		DrawTree(Ptr->right, space);

		// Print current node after space
		
		cout << endl;

		for (int i = 5; i < space; i++)
			cout << " ";
		
		cout << Ptr->key;

		// Process left child
		DrawTree(Ptr->left, space);
	}
	else
	{
		cout << "\nДерево пусто.\n";
	}
}

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

template <typename T>
BST<T>::~BST()
{}
