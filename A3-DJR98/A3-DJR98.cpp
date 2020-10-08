// A3-DJR98.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"
#include "Menu.h"

int main()
{
    bool isContinue = true;
    int choice;
    TreeNode* startNode = new TreeNode;

    do {
        displayOperations();
        getOperation(choice);
        callToTree(choice, startNode);
    } while (isContinue);
}