#include <iostream>
#include <cstdlib>
#include "BST.cpp"

using namespace std;

int main()
{
	setlocale(0, "");

	while(true)
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
				MyTree.MainMenu();
                break;
            }

            case 2:
            {
                BST<double> MyTree;
				MyTree.MainMenu();
                break;
            }

            case 3:
            {
                BST<char> MyTree;
				MyTree.MainMenu();
                break;
            }

            case 4:
            {
                return 0;
            }
        }
    }
/*
    //int input = 0;


   //

    cout << "Printing the tree in order\nBefore adding numbers\n";

    myTree.PrintInOrder();


    for(i = 0; i < TreeSize; i++)
    {
        //cout << "Add = " << TreeKeys[i] << endl;
        myTree.AddLeaf(TreeKeys[i]);
    }

    cout << "Printing the tree in order\nAfter adding numbers\n";

    myTree.PrintInOrder();

    cout << endl;

    for(int i =0; i < 16; i++)
    {
        myTree.PrintChildren(TreeKeys[i]);
        cout << endl;
    }

    cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;

    cout << "Enter a key value to delete. Enter -1 to stop the process\n";

    while(input != -1)
    {
        cout << "Delete node: ";
        cin >> input;
        {
            if(input != -1)
            {
                cout << endl;
                myTree.RemoveNode(input);
                myTree.PrintInOrder();
                cout << endl;
            }
        }
    }



*/
    return 0;
}
