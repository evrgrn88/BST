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
			
			
			"15. Пузырьковая сортировка случайного вектора.\n\n" <<

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

		case 15:
			BubbleSort(type);

			/*vector<T> testvec;
			T lSearchKey;
			bool result;

			testvec.push_back(2);
			testvec.push_back(5);
			testvec.push_back(1);
			testvec.push_back(6);
			testvec.push_back(3);
			testvec.push_back(8);

			cout << "\nПоиск: ";
			cin >> lSearchKey;
			cout << endl << endl;

			result = LinearSearch(testvec, lSearchKey);

			if (result)
				cout << "\nНайдено\n";
			else
				cout << "\nНе найдено\n";*/

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
		// Вектор для отсортированной последовательности эл-тов 
		// для последовательного перехода по итератору
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

// Инфиксный обход для подсчета количества узлов
template <typename T>
void BST<T>::ShowSize()
{
    if (root != NULL)
    {
        // Стек для промежуточного хранения
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

// Поэлементное удаление левых и правых подузлов корня с замещением
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

// Поиск элемента
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
		counter++; // Счетчик просмотренных узлов для тестирования

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

// Добавление узла вручную
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
	while (exists); // Проверка на повторяющиеся узлы
	
    cout << endl;
}

// Удаление узла
template <typename T>
void BST<T>::DeleteLeaf(T key)
{
    if (root != NULL)
    {		
		// Поиск узла для удаления
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

			if (result.nodeptr->left == NULL && result.nodeptr->right == NULL) // 0 подузлов
            {
                if (result.parent == NULL) // Узел является корневым
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

            if (result.nodeptr->left == NULL || result.nodeptr->right == NULL) // 1 подузел
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

                if (result.parent == NULL) // Узел является корневым
                {
                    delete result.nodeptr;
					result.nodeptr = NULL;
                    root = Child;
                }
                else // Удаление с замещением подузлом
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

            if (result.nodeptr->left != NULL && result.nodeptr->right != NULL) // 2 подузла
            {
                // Поиск замещающего узла (наибольшего слева)
                ParentReplacement = result.nodeptr;
                NodeReplacement = result.nodeptr->left;
				result.isLeft = true; // Замещающий узел слева

                while (NodeReplacement->right != NULL)
                {
					counter++;
					ParentReplacement = NodeReplacement;
                    NodeReplacement = NodeReplacement->right;
					result.isLeft = 0; // Замещающий узел справа
                }

				result.nodeptr->key = NodeReplacement->key; // Копирование данных

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
        cout << "\nДерево пусто.\n";
    }
}

// Инфиксная сортировка с выводом в вектор
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

// Постфиксный обход
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
		search result = FindKey(mergeKey); // Поиск узла-родителя для объединения поддеревьев

		if (result.nodeptr != NULL)
		{
			if (result.parent == NULL) // Родитель - корень
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
			else if (result.isLeft == true) // Узел - слева от родителя
			{
				while (result.nodeptr->right != NULL)
				{
					Ptr = MergeSubtree(result.nodeptr, true);
					Ptr->left = result.nodeptr;
					result.parent->left = Ptr;
					result.parent = result.parent->left;
				}
			}
			else if (result.isLeft == false) // Узел - справа от родителя
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

// Отображение структуры дерева
template<typename T>
void BST<T>::DrawTree(node* Ptr, int space)
{
	if (root != NULL)
	{
		if (Ptr == NULL)
			return;
		
		// Дистанция между уровнями
		space += 5;

		// Обработка правой стороны первой
		DrawTree(Ptr->right, space);

		// Печать текущего узла после пробела
		cout << endl;

		for (int i = 5; i < space; i++)
			cout << " ";
		
		cout << Ptr->key;

		// Обработка левой стороны
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
	unsigned int insertCounter = 0; // Счетчик для тестирования
	
	ClearTree(root);

	T key = NULL;
	bool exists;

	srand((unsigned int)time(NULL)); // Инициализация генератора случайных значений (часы)

	for (unsigned int i = 0; i < size; i++)
	{
		do
		{
			if (type == 3) // Символ от a до z;
				key = (rand() % 26) + 'a';
			else if (type == 2) // Число с плавающей точкой
				key = (T)(rand()) / (rand());
			else if (type == 1) // Целое число
				key = ((rand() + 1) * (rand() + 1) / (rand() + 1));

			exists = AddLeaf(key, root);
		} while (exists);

		insertCounter += counter;
	}

	return insertCounter;
}

// Тестирование коллекции
template<typename T>
void BST<T>::TestTree(short type)
{	
	bool exists;
	
	unsigned int size;
	unsigned int searchCounter = 0;
	unsigned int insertCounter = 0;
	unsigned int deleteCounter = 0;

	vector<T> v; // Вектор для промежуточного хранения

	srand((unsigned int)time(NULL)); // Инициализация генератора случайных значений (часы)

	if (type != 3)
	{
		// Последовательная обработка деревьев от 10 до 100000 элементов, с шагом 10,
		// средний случай
		for (size = 10; size < 100001; size *= 10) 
		{
			cout << "\n\nРазмер: " << size << " элементов.\n";
			
			cout << "\nСреднее число пройденных узлов:\n";

			counter = 0;

			// Генерация дерева с поодсчетом просмотренных узлов
			insertCounter = GenerateTree(size, type);

			cout << "Вставка: " << insertCounter / size << endl;

			// Помещение элементов дерева в вектор по возрастанию
			v = SortInOrder(root);

			counter = 0;
			
			// Последовательный поиск всех узлов с подсчетом пройденных
			for (auto i : v)
			{
				FindKey(i);
				searchCounter += counter;
			}

			cout << "Поиск: " << searchCounter / size << endl;
			
			// Удаление всех элементов дерева случайным образом с подсчетом
			// просмотренных узлов
			for (unsigned int i = 0; i < size; i++)
			{
				// Выбор случайного элемента вектора
				unsigned int key = (rand() % v.size());
				
				DeleteLeaf(v.at(key)); // Удаление элемента дерева
				v.erase(v.begin() + key); // Удаление элемента вектора
				deleteCounter += counter;
			}

			cout << "Удаление: " << deleteCounter / size << endl << endl;
		}

		cout << endl;

		searchCounter = 0;
		insertCounter = 0;
		deleteCounter = 0;

		// Худший случай (на входе - упорядоченный вектор)
		for (size = 10; size < 100001; size *= 10)
		{
			cout << "\n\nРазмер: " << size << " элементов.\n";

			cout << "\nСреднее число пройденных узлов (худший случай):\n";

			GenerateTree(size, type);

			// Создание упорядоченного вектора случайных значений
			v = SortInOrder(root);

			ClearTree(root);

			counter = 0;

			// Генерация дерева с подсчетом просмотренных узлов
			for (auto i = v.rbegin(); i != v.rend(); i++)
			{
				do
					exists = AddLeaf(*i, root);
				while (exists);

				insertCounter += counter;
			}

			cout << "Вставка: " << insertCounter / size << endl;

			counter = 0;

			// Последовательный поиск всех узлов с подсчетом пройденных
			for (auto i = v.rbegin(); i != v.rend(); i++)
			{
				FindKey(*i);
				searchCounter += counter;
			}

			cout << "Поиск: " << searchCounter / size << endl;

			// Удаление всех элементов дерева случайным образом с подсчетом
			// просмотренных узлов
			for (unsigned int i = 0; i < size; i++)
			{
				// Выбор случайного элемента вектора
				unsigned int key = (rand() % v.size());

				DeleteLeaf(v.at(key)); // Удаление элемента дерева
				v.erase(v.begin() + key); // Удаление элемента вектора
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

		// Тестирование вырожденного дерева
		cout << "\nДля символьного типа размер дерева ограничен 26 элементами (пока).\n";

		size = 26;

		cout << "\n\nРазмер: " << size << " элементов.\n";
		cout << "\nСреднее число пройденных узлов (худший случай):\n";

		GenerateTree(size, type);

		v = SortInOrder(root);

		ClearTree(root);

		counter = 0;

		// Генерация дерева с подсчетом просмотренных узлов
		for (auto i = v.rbegin(); i != v.rend(); i++)
		{
			do
				exists = AddLeaf(*i, root);
			while (exists);

			insertCounter += counter;
		}

		cout << "Вставка: " << insertCounter / size << endl;

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

	srand((unsigned int)time(NULL)); // Инициализация генератора случайных значений (часы)

	cout << "\nВведите размер вектора: ";
	cin >> size;

	for (unsigned int i = 0; i < size; i++)
	{
		do
		{
			if (type == 3) // Символ от a до z;
				key = (rand() % 26) + 'a';
			else if (type == 2) // Число с плавающей точкой
				key = (T)(rand()) / (rand());
			else if (type == 1) // Целое число
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
	
	cout << "Введите размер: ";
	cin >> size;
	
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		cin >> key;
		//cout << key << " ";
		vec.push_back(key);
		//cout << endl << vec.back() << endl;
	}
	
	cout << endl;
	
	for (auto i : vec)
		cout << i << " ";
		
	cout << endl << endl;
}

template<typename T>
void BST<T>::BubbleSort(short type)
{
	//vector<T> vec = GenerateVector(type);
	
	vector<T> vec = EnterVector();
	
	unsigned int size = vec.size();
	T left, right;
	T temp;

	for (auto i : vec)
		cout << i << " ";

	cout << endl << endl;

	typename vector<T>::iterator it = vec.begin();
	
	while (it != vec.end())
	{
		left = *it;
		right = *++it;

		if (left > right)
		{
			*it-- = left;
			*it = right;
		}
		
		for (auto i : vec)
		cout << i << " ";
		
		cout << endl;
	}
}

template <typename T>
BST<T>::~BST()
{}