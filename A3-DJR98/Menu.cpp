#include "Menu.h"
#include <iostream>

void displayOperations() {
	std::cout << "Operations:" << std::endl;
	std::cout << "1. Insert" << std::endl;
	std::cout << "2. Search" << std::endl;
	std::cout << "3. Delete" << std::endl;
	std::cout << "4. Print From Highest to Lowest" << std::endl;
	std::cout << "5. Most Expensive Path" << std::endl;
	std::cout << "6. Print In Tree Format" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

void getOperation(int& operationChoice) {
	bool validInput = true;
	do {
		std::cout << "Enter an option from the menu: ";
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

void callToInsert(TreeNode*& startNode) {
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
			startNode = insert(startNode, tempData);

			validInput = true;
		}
	} while (!validInput);
}

void callToSearch(TreeNode*& startNode) {
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
			bool doesExist = search(startNode, tempData);

			if (doesExist) {
				std::cout << "Node exists in tree." << std::endl;
			}
			else {
				std::cout << "Node does not exist in tree." << std::endl;
			}

			validInput = true;
		}
	} while (!validInput);
}

void callToDelete(TreeNode*& startNode) {
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
			deleteNode(startNode, tempData);

			validInput = true;
		}
	} while (!validInput);
}

void operatorController(int& choice, TreeNode*& startNode) {
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
		callToDelete(startNode);
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
}