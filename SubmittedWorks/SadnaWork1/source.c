/*
Assigned by:
Ran Abramovich 315942235
Nir Chodorov 316118421
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define M 2
#define N 2
#define P 3

int *powerArray(int n);
void printArray(unsigned int *arr, int n);
void printMatrix(int **arr, int rows, int columns);
int** multiplyTwoMatrix(int arr1[M][N], int arr2[N][P]);



typedef int FIELD_TYPE;

typedef struct SummedIndexFields
{
	FIELD_TYPE sum;
	FIELD_TYPE iIndex;
	FIELD_TYPE jIndex;
} SummedIndexFields;

typedef SummedIndexFields NODE_TYPE;

typedef struct Node{
	NODE_TYPE nodeData;
	struct Node *nextNode;
} Node;

typedef struct IntList {
	int nodeData;
	struct IntList *nextNode;
}IntList;

typedef enum { Int, Double, Char, SummedIndexField } NODE_TYPE_ENUM;

//For Ex1-Ex5 : Get the requested input from user and call the specific functions.
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

int main()
{
	int num = 0;
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf("%d", &select);
			} while ((select<0) || (select>5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;

			}
		} while (all_Ex_in_loop && select);
		return 0;
}

void Ex1()
{
	int n;
	unsigned int *p;
	printf("Please enter the number of the array length : \n");
	scanf("%d", &n);
	p = powerArray(n);
	printArray(p, n);
}

void Ex2()
{
	int i , j, **mat = NULL, arr1[M][N], arr2[N][P];
	printf("Enter %d integers for the first matrix : \n", M*N);
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr1[i][j]);
	printf("Enter %d integers for the second matrix : \n", N*P);
	for (i = 0; i < N; i++)
		for (j = 0; j < P; j++)
			scanf("%d", &arr2[i][j]);
	printf("The first matrix : \n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", arr1[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("The second matrix : \n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < P; j++)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}
	printf("\n");
	mat = multiplyTwoMatrix(&arr1, &arr2);
	printf("The multiply of the two matrix is : \n");
	printMatrix(mat, M, P);
}

void Ex3()
{
	//add somethign
}

void Ex4()
{

}

void Ex5()
{

}


void InsertToList(Node* listPtr, NODE_TYPE dataToAdd,NODE_TYPE_ENUM type) {
	Node newNode = (Node){.nodeData = dataToAdd , .nextNode = NULL};
	listPtr->nextNode = &newNode;
}

void RemoveFromList(IntList** list , IntList * nodeToRemove) {
	IntList *ptrHelp = list;
	while (ptrHelp != NULL) {
		if (ptrHelp->nextNode = nodeToRemove) {
			ptrHelp->nextNode = nodeToRemove->nextNode;
			free(nodeToRemove);
			return;
		}
	}
}

//Ex3
int FindMatchingToIndex(FIELD_TYPE** mat, FIELD_TYPE* arrayToSaveResults, Node* listToSaveResults) {
	int reultsCount = 0;
	NODE_TYPE indexField;
	Node *listPtr = listToSaveResults;
	for (int i = 0; i < sizeof(mat); i++) {
		for (int j = 0; j < sizeof(mat); j++) {
			if (mat[i][j] == i + j) {
				reultsCount++;
				indexField.iIndex = i;
				indexField.jIndex = j;
				indexField.sum = i + j;
				InsertToList(listPtr, indexField,SummedIndexField);
			}
		}
	}
	CreateArrayFromList(arrayToSaveResults, listToSaveResults, reultsCount);
	return reultsCount;
}

//Ex4
IntList * GetOddsFromList(IntList  *list) {
	IntList* ptrHelp = list;
	IntList* oddsList = NULL;
	IntList* oddsListHead = oddsList;
	while (ptrHelp != NULL) {
		if (ptrHelp->nodeData % 2 != 0) {
			//So far using the same function
			InsertToList(oddsList, ptrHelp->nodeData, Int);
			RemoveFromList(&list, ptrHelp);
		}
	}
	return oddsListHead;
}


int *powerArray(int n)
{
	int *arr, i;
	arr = (int*)malloc(n* sizeof(int));
	if (arr == 0)
		return 0;
	for (i = 0; i < n; i++)
	{
		arr[i] = pow((double)2, (double)(i % 32));
	}
	return arr;
}

void printArray(unsigned int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void printMatrix(int **arr, int rows, int columns)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

CreateArrayFromList(FIELD_TYPE* arrayToSaveResults, Node* listToSaveResults,int size) {
	arrayToSaveResults = (FIELD_TYPE*)malloc(size * sizeof(FIELD_TYPE));
	for (int i = 0; i < (size*3) - 3; i+=3) {
		arrayToSaveResults[i] = listToSaveResults->nodeData.sum;
		arrayToSaveResults[i+1] = listToSaveResults->nodeData.jIndex;
		arrayToSaveResults[i+2] = listToSaveResults->nodeData.iIndex;
		listToSaveResults = listToSaveResults->nextNode;
	}
}


int** multiplyTwoMatrix(int arr1[M][N], int arr2[N][P])
{
	int i, j, k, **mat, sum = 0;
	mat = (int **)malloc(sizeof(int)*M);
	for (i = 0; i < M; i++)
		mat[i] = (int*)malloc(sizeof(int)*P);
	for (i = 0; i < M; i++)
		for (j = 0; j < P; j++)
		{
			for (k = 0; k < N; k++)
				sum += arr1[i][k] * arr2[k][j];
			mat[i][j] = sum;
			sum = 0;
		}
	return mat;
}