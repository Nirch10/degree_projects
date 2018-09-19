#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdlib.h>
#include<stdio.h>
#include "BinTree.h"

#pragma region Functions Declaretion
void CreateSearchBinTree(BinTreeNode* tree);
void InsertToSearchedTree(BinTreeNode* searchedTree, BinTreeNode* newNode);
void CreateRegBinTree(BinTreeNode* tree);
#pragma endregion

#pragma region Def Declerations
//#define PrintInorder "PrintInOrder";
//#define AddLeftSon "InsertLeftNode";
//#define AddRightSon "InsertRightNode";
#pragma endregion 



void main() {
	BinTreeNode* tree1 = NULL;
	InitBinTree(tree1);
	CreateSearchBinTree(&tree1);
	PrintInOrder(tree1);
}

void CreateSearchBinTree(BinTreeNode ** tree)
{
	BinTreeNode* newNode =NULL;
	int isFinished = 0, data = 0;
	printf("Youre about to create a search Binary tree :) ! \nbetween each node youll by asked whether to finish creating the tree\nWhen you decide to stop - just enter 15 ,otherwise type any number(int pls!)");
	printf("Lets try it : Do you want to start? (if you wish to stop press 15)\n");
	scanf("%d", &isFinished);
	while (isFinished != 15)
	{
		printf("You decided to add node to our searched binary tree - press its int data\n");
		scanf("%d", &data);
		newNode = CreateNode(data);
		InsertToSearchedTree(tree, newNode);
		printf("If you want to stop adding nodes to the searced tree press 15\n");
		scanf("%d", &isFinished);
	}

}

void InsertToSearchedTree(BinTreeNode** searchedTree,BinTreeNode* newNode){
	if (IsBinTreeEmpty(*searchedTree)) {
		*searchedTree= newNode;
		return;
	}
	
	if ((*searchedTree)->data > newNode->data) {
		if ((*searchedTree)->left == NULL) {
			(*searchedTree)->left = newNode;
			newNode->parent = *searchedTree;
			return;
		}
		InsertToSearchedTree(&(*searchedTree)->left, newNode);
	}

	else {
		if ((*searchedTree)->right == NULL) {
			(*searchedTree)->right = newNode;
			newNode->parent = *searchedTree;
			return;
		}
		InsertToSearchedTree(&(*searchedTree)->right, newNode);
	}
}



void CreateRegBinTree(BinTreeNode * tree)
{
	BinTreeNode * ptr = tree;
	int data = 0, isLeft = 0;
	scanf("%d", &data);
	while (data != -1) {
		if (ptr != NULL) {
		}
	}

}
