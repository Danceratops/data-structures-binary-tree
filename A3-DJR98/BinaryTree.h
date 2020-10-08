#pragma once

class TreeNode {
public:
	TreeNode *left, *right;
	int treeData;
};

TreeNode* newNode(int);

TreeNode* search(TreeNode*, int);

TreeNode* insert(TreeNode*, int);

TreeNode* minValueNode(TreeNode*);

TreeNode* deleteNode(TreeNode*, int);

void printTree(TreeNode*, int);

void printTreeInOrder(TreeNode*);

int maxSumPath(TreeNode*);

void getTargetLeaf(TreeNode*, int*, int, TreeNode**);