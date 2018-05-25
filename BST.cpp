/*
TODO:

Комментарии
*/



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
			cout << "Тип: целое число\n";
		else if (type == 2)
			cout << "Тип: число с плавающей точкой\n";
		else if (type == 3)
			cout << "Тип: символ\n";

        short choice;
        cout << endl <<
			
			"Операции:\n" <<
			"---------------------------------------------\n" <<
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
			"12. Сгенерировать дерево.\n\n" <<
			
			"Тестирование:\n" <<
			"---------------------------------------------\n" <<
			"13. Проверить производительность дерева.\n\n" <<
			"14. Назад.\n" <<

			"\n\nВыберите операцию: ";

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

			cout << "\nПоиск: ";
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

			cout << "Введите ключ: ";
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

			cout << "\nВведите число элементов: \n";

			cin >> treeSize;

			if (type == 3 && treeSize > 26)
			{
				cout << "\nДля символьного типа данных размер дерева ограничен 26 элементами (пока). Введите новый размер: \n";
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
        cout << "\nДерево пусто.\n";
    }
    else
    {
        cout << "\nДерево НЕ пусто.\n";
    }

    cout << endl;
}

template <typename T>
typename BST<T>::search BST<T>::FindKey(T key)
{
	search result;
	counter = 0;

	result.nodeptr = root;
	result.parent = NULL;
	result.isLeft = true;
		
	while (result.nodeptr != NULL) // Check if the key is present
	{
		counter++;

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
			cout << "\nЭлемент НЕ найден\n";
		else if (result.nodeptr->key == searchKey)
			cout << "\nЭлемент найден\n";
	}
	else
		cout << "\nДерево пусто.\n";
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

template <typename T>
void BST<T>::AddNewLeaf()
{
    T newKey;
	bool exists;
    
	do
	{
		cout << "\nВведите ключ: \n";
		cin >> newKey;
		exists = AddLeaf(newKey, root);

		if (exists)
			cout << "\nЭлемент уже существует!";
	}
	while (exists);
	
    cout << endl;
}

template <typename T>
void BST<T>::DeleteLeaf(T key)
{
    if (root != NULL)
    {		
		search result = FindKey(key);

		node* Child = NULL;
		node* ParentReplacement = NULL;
		node* NodeReplacement = NULL;

		if (result.nodeptr == NULL)
		{
			cout << "\nЭлемент НЕ найден\n";
			return;
		}

		if (result.nodeptr->key == key)
        {
			counter++;

			if (result.nodeptr->left == NULL && result.nodeptr->right == NULL) // 0 children
            {
                if (result.parent == NULL) // Node is a root
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

            if (result.nodeptr->left == NULL || result.nodeptr->right == NULL) // 1 child
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

                if (result.parent == NULL) // Root node is being deleted
                {
                    delete result.nodeptr;
					result.nodeptr = NULL;
                    root = Child;
                }
                else // Deleting node, parent adopting node children
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

            if (result.nodeptr->left != NULL && result.nodeptr->right != NULL) // 2 children
            {
                // Finding replacement (highest node less than node to delete)
                ParentReplacement = result.nodeptr;
                NodeReplacement = result.nodeptr->left;
				result.isLeft = true; // NodeReplacement is left child of parent

                while (NodeReplacement->right != NULL)
                {
					counter++;
					ParentReplacement = NodeReplacement;
                    NodeReplacement = NodeReplacement->right;
					result.isLeft = 0; // NodeReplacement is right child of parent
                }

				result.nodeptr->key = NodeReplacement->key; // Copying data

                if (result.isLeft) // NodeReplacement is left child of Ptr.
                {
					result.nodeptr->left = NodeReplacement->left;
                }
                else // NodeReplacement is right grandchild of Ptr->left
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
		} while (!s.empty());
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
		search result = FindKey(mergeKey);

		if (result.nodeptr != NULL)
		{
			if (result.parent == NULL)
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
			else if (result.isLeft == true)
			{
				while (result.nodeptr->right != NULL)
				{
					Ptr = MergeSubtree(result.nodeptr, true);
					Ptr->left = result.nodeptr;
					result.parent->left = Ptr;
					result.parent = result.parent->left;
				}
			}
			else if (result.isLeft == false)
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

		cout << endl << endl;
	}
	else
	{
		cout << "\nДерево пусто.\n";
	}
}

template<typename T>
unsigned int BST<T>::GenerateTree(unsigned int size, short type)
{
	unsigned int insertCounter = 0;
	
	ClearTree(root);

	T key = NULL;
	bool exists;

	srand((unsigned int)time(NULL));

	for (unsigned int i = 0; i < size; i++)
	{
		do
		{
			if (type == 3)
				key = (rand() % 26) + 'a';
			else if (type == 2)
				key = (T)(rand()) / (rand());
			else if (type == 1)
				key = ((rand() + 1) * (rand() + 1) / (rand() + 1));

			exists = AddLeaf(key, root);
		} while (exists);

		insertCounter += counter;
	}

	return insertCounter;
}

template<typename T>
void BST<T>::TestTree(short type)
{	
	unsigned int size;
	unsigned int searchCounter = 0;
	unsigned int insertCounter = 0;
	unsigned int deleteCounter = 0;

	vector<T> v;

	srand((unsigned int)time(NULL));

	if (type != 3)
	{
		for (size = 10; size < 100001; size *= 10)
		{
			cout << "\n\nРазмер: " << size << " элементов.\n";
			
			cout << "\nСреднее число пройденных узлов:\n";

			counter = 0;

			insertCounter = GenerateTree(size, type);

			cout << "Вставка: " << insertCounter / size << endl;

			v = SortInOrder(root);

			counter = 0;
			
			for (auto i : v)
			{
				FindKey(i);
				searchCounter += counter;
			}

			cout << "Поиск: " << searchCounter / size << endl;
			
			for (unsigned int i = 0; i < size; i++)
			{
				unsigned int key = (rand() % v.size());
				
				DeleteLeaf(v.at(key));
				v.erase(v.begin() + key);
				deleteCounter += counter;
			}

			cout << "Удаление: " << deleteCounter / size << endl << endl;
		}

		cout << endl;
	}
	else
	{
		cout << "\nДля символьного типа размер дерева ограничен 26 элементами (пока).\n";

		size = 26;
		
		cout << "\n\nРазмер: " << size << " элементов.\n";
		cout << "\nСреднее число пройденных узлов:\n";

		counter = 0;

		insertCounter = GenerateTree(size, type);

		cout << "Вставка: " << insertCounter / size << endl;

		v = SortInOrder(root);

		counter = 0;

		for (auto i : v)
		{
			FindKey(i);
			searchCounter += counter;
		}

		cout << "Поиск: " << searchCounter / size << endl;

		for (unsigned int i = 0; i < size; i++)
		{
			unsigned int key = (rand() % v.size());

			DeleteLeaf(v.at(key));

			v.erase(v.begin() + key);

			deleteCounter += counter;
		}

		cout << "Удаление: " << deleteCounter / size << endl;
		cout << endl;
	}
}

template <typename T>
BST<T>::~BST()
{}
