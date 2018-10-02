/*
Assigned by:
Ran Abramovich 315942235
Nir Chodorov 316118421
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdlib.h>
#include<stdio.h>
#include "BinTree.h"
#include "Queue_point.h"

#pragma region Functions Declaretion
int ChooseEx();
void CreateSearchBinTree(BinTreeNode** tree);
void InsertToSearchedTree(BinTreeNode ** searchedTree, BinTreeNode * newNode);
void PrintTreeByHeight(BinTreeNode* tree);
void FreeTree(BinTreeNode * tree);
#pragma endregion

#pragma region Def Declerations
//#define PrintInorder "PrintInOrder";
//#define AddLeftSon "InsertLeftNode";
//#define AddRightSon "InsertRightNode";
#pragma endregion 



void main() {

	int currentChoise = 6;
	BinTreeNode* tr = NULL;
	
	currentChoise = ChooseEx();
	while (currentChoise != 0) {
		switch (currentChoise) {
		case 1: {InitBinTree(tr); 
				CreateSearchBinTree(&tr);
				break;
		}
		case 2:
		{if (IsBinTreeEmpty(tr))
			printf("tree empty\n");
		else
			printf("tree not empty\n");
			break; }
		case 3:
			PrintInOrder(tr);
			break;
		case 4: {
			printf("\n");
			PrintTreeByHeight(tr);
			break; }
		case 5:
		{	FreeTree(tr); 
		break; }
		default:
		{
			currentChoise = 0;
			FreeTree(tr);
		
		}
		}
		if (currentChoise != 0)
			currentChoise = ChooseEx();
	}


	
	
	
}

int ChooseEx() {
	int currentChoise = 0;
	printf("\nHello, welcome to our BinTree Factory!\nTo Create One pls press 1\nTo Check your tree status pls press 2\nTo print your tree In order pls press 3\nTo print your tree by height pls press 4\nTo release your tree pls press 5\nTo exit press 0\n");
	scanf("\n%d", &currentChoise);
	return currentChoise;

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

void PrintTreeByHeight(BinTreeNode* tree) {
	BinTreeNode *helper;
	queue hQueue ;
	create_queue(&hQueue);
	if (IsBinTreeEmpty(tree))return;
	enqueue(tree, &hQueue);
	while (!queue_is_empty(&hQueue)) {
		dequeue(&hQueue, &helper);
		printf("%d ", helper->data);
		if (helper->left)
			enqueue((helper->left), &hQueue);
		if (helper->right)
			enqueue(helper->right, &hQueue);
	}
}

void FreeTree(BinTreeNode* tree) {
	if (IsBinTreeEmpty(tree))
		return;
	FreeTree(tree->left);
	FreeTree(tree->right);
	tree->left = NULL;
	tree->right = NULL;
	tree->data = NULL;
	free(tree);
}
