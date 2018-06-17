#ifndef BST_H
#define BST_H

using namespace std;

template <typename T> class BST
{
private:
	
	// Определение узла дерева
	struct node
    {
        T key;
        node* left;
        node* right;
    };

	// Структура для вывода результатов поиска
	// Включает в себя указатель на узел-родитель и флаг положения искомого узла
	struct search
	{
		node* nodeptr;
		node* parent;
		bool isLeft;
	};

	// Итератор для доступа к элементам дерева
	typename vector<T>::iterator iterator;

    // Объявление корневой переменной
	node* root;

	// Глобальная переменная для передачи в функции типа данных дерева
	short type;

	// Инициализация счетчика узлов
	int counter = 0;

	// Заполнение дерева вручную
    void FillTree();

	// Очистка дерева
    void ClearTree(node* Ptr);

	// Вывод размера
    void ShowSize();

	// Проверка на пустоту
    void EmptyCheck(node* Ptr);

	// Поиск по ключу
	search FindKey(T key);

	// Текстовый интерфейс функции поиска
	void FindKeyHelper(T searchKey);

	// Создание узла дерева в куче
    node* CreateLeaf(T key);

	// Добавление узла. Вывод - наличие совпадения в дереве для повторного создания
    bool AddLeaf(T key, node* Ptr);

	// Текстовый интерфейс функции добавления узла вручную
	void AddNewLeaf();

    // Удаление узла с замещением
	void DeleteLeaf(T key);

	// Сортировка (инфиксный обход), вывод в вектор
	vector<T> SortInOrder(node* Ptr);

	// Печать инфикс-вектора
	void PrintInOrder();

    // Постфиксный обход
	void PrintPostOrder(node* Ptr);

	// Подготовка функции слияния
	void MergePrepare();

	// Функция рекурсивного слияния соседних поддеревъев
	node* MergeSubtree(node* Ptr, bool isLeft);

	// Создание дерева из случайных элементов
	unsigned int GenerateTree(unsigned int size, short type);

	// Отображение структуры дерева
	void DrawTree(node* Ptr, int space);

	// Тестирование дерева от 10 до 100000 узлов.
	// Среднее число посещённых узлов для операций вставки, поиска и удаления
	void TestTree(short type);

	// Линейный поиск по вектору
	bool LinearSearch(vector<T> v, T key);

	// Генерация вектора заданной длины
	vector<T> GenerateVector(short type);

	// Пузырьковая сортировка элементов вектора
	void BubbleSort(short type);

public:
	BST();
    ~BST();

    void MainMenu(short type);

	void IteratorMenu();
};

#endif
