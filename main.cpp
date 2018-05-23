#include <iostream>
#include <cstdlib>
#include "BST.cpp"

using namespace std;

void main()
{
	setlocale(0, "");

	while (true)
    {
        system("cls");

        short choice;

        cout << endl <<

                "1. Целое число.\n" <<
                "2. Число с плавающей точкой.\n" <<
                "3. Символ.\n\n" <<

                "4. Выход.\n" <<

                "\n\nВыберите тип: ";

        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
            {
                BST<int> MyTree;
				MyTree.MainMenu(choice);
                break;
            }

            case 2:
            {
                BST<double> MyTree;
				MyTree.MainMenu(choice);
                break;
            }

            case 3:
            {
                BST<char> MyTree;
				MyTree.MainMenu(choice);
                break;
            }

            case 4:
            {
                return;
            }
        }
    }
}
