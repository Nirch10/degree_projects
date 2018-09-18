#include "BinTree.h"

#pragma region Defining Functions
//Gets binTreeNode by value!, prints the tree by in-order itterative
//void PrintInOrder(BinTreeNode binTree);
//Gets data typed int and string to add after data- and prints them to console
void PrintNodeInt(int data, char* sep);
//Gets bintreenode pointer be the parent and one to be his left son - and connects them 
void InsertLeftNode(BinTreeNode* nodeParent, BinTreeNode * newNode);
//Gets bintreenode pointer be the parent and one to be his right son - and connects them 
void InsertRightNode(BinTreeNode* nodeParent, BinTreeNode * newNode);
#pragma endregion

void InitBinTree(BinTreeNode* binTree) {
	binTree = NULL;
}

void IsBinTreeEmpty(BinTreeNode* binTree) {
	return binTree == NULL;
}

BinTreeNode* CreateNode(DATA_TYPE data) {
	BinTreeNode* newNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	SetNodeData(newNode,data);
	newNode->left = NULL;
	newNode->parent = NULL;
	newNode->right = NULL;
	return newNode;
}

DATA_TYPE SetNodeData(BinTreeNode* nodeToSet, DATA_TYPE newData) {
	DATA_TYPE oldData = nodeToSet->data;
	nodeToSet->data = newData;
	return oldData;
}

BinTreeNode* SetNodeParent(BinTreeNode*nodeToSet, BinTreeNode * newParent) {
	BinTreeNode* oldParent = nodeToSet->parent;
	nodeToSet->parent = newParent;
	return oldParent;
}

void InsertNode(BinTreeNode* nodeParent, BinTreeNode * newNode, int isLeft) {
	if (nodeParent == NULL)nodeParent = newNode;
	else if (isLeft == 0)InsertLeftNode(nodeParent, newNode);
	else InsertRightNode(nodeParent, newNode);
}

void PrintBinTree(BinTreeNode binTree, void(*PrintFunction)(BinTreeNode binTree)) {
	(*PrintFunction)(binTree);
}

#pragma region Private Methods

void PrintInOrder(BinTreeNode *binTree) {
	int leftDone = 0;
	BinTreeNode* binPtr = binTree;
	while (binPtr != NULL)
	{
		if (leftDone == 0)
			while (binPtr->left != NULL)
				binPtr = binPtr->left;
		printf(" %d ", binPtr->data);
		leftDone = 1;
		if (binPtr->right != NULL) {
			leftDone = 0;
			binPtr = binPtr->right;
		}
		else if (binPtr->parent != NULL) {
			while (binPtr->parent != NULL&& binPtr == binPtr->parent->right)binPtr = binPtr->parent;
			if (binPtr->parent != NULL)binPtr = binPtr->parent;
		}
		else binPtr = NULL;
	}

}

void PrintNodeInt(int data, char* sep) {
	printf("%d%s", data, sep);
}

void InsertLeftNode(BinTreeNode* nodeParent, BinTreeNode * newNode) {
	nodeParent->left = newNode;
}

void InsertRightNode(BinTreeNode* nodeParent, BinTreeNode * newNode) {
	nodeParent->right = newNode;
}
#pragma endregion

//BinTreeNode* binPtr = binTree;
//int isLeft = 0;
//stack * nodeStack = NULL;
//create_stack(nodeStack);
//char* seperator = ' , ';
//push((*binPtr), nodeStack);
//while (binPtr != NULL && !stack_is_empty(nodeStack))
//{
//	if (binPtr->left != NULL&& binPtr->data != NULL) {
//		push(*(binPtr->left), nodeStack);
//		binPtr = binPtr->left;
//	}
//	else {
//		PrintNodeInt(binPtr->data, seperator);
//		binPtr->data = NULL;
//		if (binPtr->right != NULL && binPtr->data != NULL) {
//			binPtr = binPtr->right;
//		}
//		else {
//			pop(nodeStack, binPtr);
//		}
//	}
//}