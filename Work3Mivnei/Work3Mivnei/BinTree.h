#include <stdlib.h>
#include <stdio.h>
typedef int DATA_TYPE;
#pragma once
typedef struct BinTreeNode
{
	DATA_TYPE data;
	struct BinTreeNode* parent;
	struct BinTreeNode* left;
	struct BinTreeNode* right;

}BinTreeNode;

//Gets a pointer to new tree node and creates new empty binTree
void InitBinTree(BinTreeNode* binTree);

void IsBinTreeEmpty(BinTreeNode* binTree);

//Gets node and a parent - adds it to node
void InsertNode(BinTreeNode* nodeParent, BinTreeNode * newNode, int isLeft);

//Gets a datatype data to insert to new empty node which is being created , returns a pointer to the new node
BinTreeNode* CreateNode(DATA_TYPE data);

//Gets tree and a node to remove , and removes it from tree
//void RemoveNode(BinTreeNode ** binTree, BinTreeNode * nodeToRemove);

//Gets a binTreeNode and a new dataType , change the furrent's node data to "newData" and returns the old value
DATA_TYPE SetNodeData(BinTreeNode* nodeToSet,DATA_TYPE newData);

//Gets a binTreeNode and a new binTreeNode to be the new parent, change the furrent's node Parent to "newParent" and returns the old value
BinTreeNode* SetNodeParent(BinTreeNode*nodeToSet,BinTreeNode * newParent);

//Gets a binTreeNode and a new dataType , change the furrent's node data to "newData" and returns the old value
//BinTreeNode* SetNodeSon(BinTreeNode* nodeToSet, BinTreeNode* newData);

void PrintBinTree(BinTreeNode binTree, void(*PrintFunction)(BinTreeNode binTree));

void PrintInOrder(BinTreeNode *binTree);


