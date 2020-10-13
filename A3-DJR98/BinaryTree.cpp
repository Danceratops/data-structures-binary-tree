#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "BinaryTree.h"

TreeNode* newNode(int givenData)
{
	TreeNode* node = new TreeNode;
	node->treeData = givenData;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

bool search(TreeNode* currentNode, int nodeData)
{
	if (currentNode == nullptr) {
		return false;
	}

	if (currentNode->treeData == nodeData) {
		return true;
	}

	bool recurSearch = search(currentNode->left, nodeData);

	if (recurSearch) {
		return true;
	}

	recurSearch = search(currentNode->right, nodeData);

	return recurSearch;

}

TreeNode* insert(TreeNode*& root, int dataToInsert)
{
	if (root == nullptr) {
		std::cout << dataToInsert << " has been inserted successfully." << std::endl;
		return newNode(dataToInsert);
	}
	else {
		if (dataToInsert <= root->treeData)
		{
			root->left = insert(root->left, dataToInsert);
		}
		else {
			root->right = insert(root->right, dataToInsert);
		}
	}

	return root;
}

TreeNode* minValueNode(TreeNode* givenNode)
{
	TreeNode* currentNode = givenNode;

	/* loop down to find the leftmost leaf */
	while (currentNode && currentNode->left != NULL)
	{
		currentNode = currentNode->left;
	}

	return currentNode;
}

TreeNode* deleteNode(TreeNode* givenNode, int givenData)
{
	if (givenNode == NULL)
	{
		return givenNode;
	}

	if (givenData < givenNode->treeData)
	{
		givenNode->left = deleteNode(givenNode->left, givenData);
	}

	else if (givenData > givenNode->treeData)
	{
		givenNode->right = deleteNode(givenNode->right, givenData);
	}

	else
	{
		if (givenNode->left == NULL)
		{
			TreeNode* temp = givenNode->right;
			free(givenNode);
			std::cout << "Node deleted" << std::endl;
			return temp;
		}
		else if (givenNode->right == NULL)
		{
			TreeNode* temp = givenNode->left;
			free(givenNode);
			std::cout << "Node deleted" << std::endl;
			return temp;
		}

		TreeNode* temp = minValueNode(givenNode->right);

		givenNode->treeData = temp->treeData;

		givenNode->right = deleteNode(givenNode->right, temp->treeData);
	}

	return givenNode;
}

void printTree(TreeNode* givenNode, int indent)
{
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}

	std::cout << givenNode->treeData << '\n';
	if (givenNode->left)
	{
		printTree(givenNode->left, indent);
	}
	if (givenNode->right)
	{
		printTree(givenNode->right, indent);
	}
}

void printTreeInOrder(TreeNode* givenNode)
{
	if (givenNode == NULL)
	{
		return;
	}

	printTreeInOrder(givenNode->left);
	std::cout << givenNode->treeData << " \n";
	printTreeInOrder(givenNode->right);
}

void maxSumPath(TreeNode* givenNode)
{
	if (givenNode == NULL)
		return;

	TreeNode* targetNode;
	int maxSum = INT_MIN;

	getTargetLeaf(givenNode, &maxSum, 0, &targetNode);

	std::cout << "Most expensive path is " << maxSum << std::endl;
}

void getTargetLeaf(TreeNode* givenNode, int* maxSum, int currentSum, TreeNode** targetNode)
{
	if (givenNode == NULL)
		return;

	currentSum = currentSum + givenNode->treeData;

	if (givenNode->left == NULL && givenNode->right == NULL) {
		if (currentSum > * maxSum) {
			*maxSum = currentSum;
			*targetNode = givenNode;
		}
	}

	getTargetLeaf(givenNode->left, maxSum, currentSum,
		targetNode);
	getTargetLeaf(givenNode->right, maxSum, currentSum,
		targetNode);
}