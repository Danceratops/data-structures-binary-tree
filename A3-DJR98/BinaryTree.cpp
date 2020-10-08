#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "BinaryTree.h"

TreeNode* newNode(int givenData)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->treeData = givenData;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* search(TreeNode* currentNode, int nodeData)
{
	if (currentNode == nullptr || currentNode->treeData == nodeData)
	{
		return currentNode;
	}

	if (currentNode->treeData < nodeData)
	{
		return search(currentNode->right, nodeData);
	}

	return search(currentNode->left, nodeData);
}

TreeNode* insert(TreeNode* nodeToInsert, int dataToInset)
{
	if (nodeToInsert == NULL)
	{
		return newNode(dataToInset);
	}

	if (dataToInset < nodeToInsert->treeData)
	{
		nodeToInsert->left = insert(nodeToInsert->left, dataToInset);
	}

	else if (dataToInset > nodeToInsert->treeData)
	{
		nodeToInsert->right = insert(nodeToInsert->right, dataToInset);
	}

	return nodeToInsert;
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
			return temp;
		}
		else if (givenNode->right == NULL)
		{
			TreeNode* temp = givenNode->left;
			free(givenNode);
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
	std::cout << givenNode->treeData << " ";
	printTreeInOrder(givenNode->right);
}

int maxSumPath(TreeNode* givenNode)
{
	if (givenNode == NULL)
		return 0;

	TreeNode* targetNode;
	int maxSum = INT_MIN;

	getTargetLeaf(givenNode, &maxSum, 0, &targetNode);

	return maxSum;
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