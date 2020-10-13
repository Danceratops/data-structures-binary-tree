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
        operatorController(choice, startNode);
    } while (isContinue);

	return 0;
}