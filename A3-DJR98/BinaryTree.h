#pragma once

struct TreeNode {
	TreeNode *left, *right;
	int treeData;
};

TreeNode* newNode(int);

bool search(TreeNode*, int);

TreeNode* insert(TreeNode* &, int);

TreeNode* minValueNode(TreeNode*);

TreeNode* deleteNode(TreeNode*, int);

void printTree(TreeNode*, int);

void printTreeInOrder(TreeNode*);

void maxSumPath(TreeNode*);

void getTargetLeaf(TreeNode*, int*, int, TreeNode**);