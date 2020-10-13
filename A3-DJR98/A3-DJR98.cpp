// A3-DJR98.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "Menu.h"

int main()
{
    bool isContinue = true;
    int choice;
	int tempData;
    TreeNode* startNode = nullptr;

    do {
        displayOperations();
        getOperation(choice);

		switch (choice)
		{
		case 1:
		{
			callToInsert(startNode);
		}
		break;
		case 2:
		{
			callToSearch(startNode);
		}
		break;
		case 3:
		{
			bool validInput = true;

			do {
				std::cout << "Enter data to be deleted: ";
				std::cin >> tempData;

				if (std::cin.fail())
				{
					validInput = false;
				}
				else
				{
					deleteNode(startNode, tempData);

					validInput = true;
				}
			} while (!validInput);
		}
		break;
		case 4:
		{
			printTreeInOrder(startNode);
			std::cout << "\n";
		}
		break;
		case 5:
		{
			maxSumPath(startNode);
		}
		break;
		case 6:
		{
			printTree(startNode, 0);
		}
		break;
		case 7:
		{
			std::cout << "Now exiting program..." << std::endl;
			exit(0);
		}
		break;
		default:
			break;
		}
    } while (isContinue);

	return 0;
}