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