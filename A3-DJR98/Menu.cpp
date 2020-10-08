#include "Menu.h"
#include <iostream>

void displayOperations() {
	std::cout << "Operations:" << std::endl;
	std::cout << "1. Insert" << std::endl;
	std::cout << "2. Search" << std::endl;
	std::cout << "3. Delete" << std::endl;
	std::cout << "4. Print Sorted Order" << std::endl;
	std::cout << "5. Most Expensive Path" << std::endl;
	std::cout << "6. Print In Tree Format" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

void getOperation(int& operationChoice) {
	bool validInput = true;
	do {
		std::cin >> operationChoice;
		if (std::cin.fail() || operationChoice > 7 || operationChoice < 1)
		{
			std::cout << "Please enter a numerical value between 1 and 7." << std::endl;
			validInput = true;
		}
		else
		{
			validInput = false;
		}
	} while (validInput);
}

void callToTree(int operationChoice, TreeNode* givenNode) {
	switch (operationChoice)
	{
	case 1:
	{
		callToInsert(givenNode);
	}
	break;
	case 2:
	{
		callToSearch(givenNode);
	}
	break;
	case 3:
	{
		callToDelete(givenNode);
	}
	break;
	case 4:
	{
		printTreeInOrder(givenNode);
	}
	break;
	case 5:
	{
		maxSumPath(givenNode);
	}
	break;
	case 6:
	{
		printTree(givenNode, 0);
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
}

void callToInsert(TreeNode* givenNode) {
	int tempData;
	bool validInput = true;
	do {
		std::cout << "Enter data to be stored: ";
		std::cin >> tempData;
		if (std::cin.fail()) {
			validInput = false;
		}
		else
		{
			insert(givenNode, tempData);
			validInput = true;
		}
	} while (!validInput);

}

void callToSearch(TreeNode* givenNode) {
	int tempData;
	bool validInput = true;
	do {
		std::cout << "Enter data to find: ";
		std::cin >> tempData;

		if (std::cin.fail())
		{
			validInput = false;
		}
		else
		{
			TreeNode* tempNode = search(givenNode, tempData);

			if (tempNode->treeData == NULL) {
				std::cout << "Data not found." << std::endl;
			}
			else {
				std::cout << "Node exists." << std::endl;
			}

			validInput = true;
		}
	} while (!validInput);
}

void callToDelete(TreeNode* givenNode) {
	int tempData;
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
			deleteNode(givenNode, tempData);
			validInput = true;
		}
	} while (!validInput);
}