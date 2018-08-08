#include "Queue_point.h"
#include "Stack_point.h"
#include "Printer.h"


void PrintStack(STRUCT_TYPE *s, StructDataType dataType,void *helperVar, char *devider);
void PrintQueue(STRUCT_TYPE *q, StructDataType dataType, void *helperVar, char *devider);
void PrintCharArrays(char *arrayToPrint, StructDataType dataType, void* helper, int columnSize, int rowSize, char *devider);
void PrintIntArrays(int *arrayToPrint, StructDataType dataType, void* helper, int columnSize, int rowSize, char *devider);
void PrintNode(void *node, StructDataType dataType);
void PrintDevider(char *devider);




void PrintComplexStruct(STRUCT_TYPE *structToPrint, StructType typeOfStruct, StructDataType dataType,void *helperVar,char *devider) {
	switch (typeOfStruct)
	{
	case Stack:PrintStack(structToPrint,dataType, helperVar,devider);
		break;
	case Queue:PrintQueue(structToPrint,dataType, helperVar,devider);
		break;
	}
}

void PrintStack(STRUCT_TYPE *s, StructDataType dataType,void *helperVar, char *devider){
	//Not generic type
	while (!stack_is_empty(s) ){
		pop(s, &helperVar);
		PrintNode(helperVar, dataType);
		if (!stack_is_empty(s))
			PrintDevider(devider);
	}
}

void PrintQueue(STRUCT_TYPE *q, StructDataType dataType, void *helperVar,char *devider) {
	//Not generic type
	while (!queue_is_empty(q)) {
		dequeue(q, &helperVar);
		PrintNode(helperVar, dataType);
		if(!queue_is_empty(q))
			PrintDevider(devider);
	}
}

void PrintArrayStruct(void* arrayToPrint, StructDataType dataType, void *helperVar,int columnSize,int rowSize, char *devider){
	
	switch (dataType)
	{
	case Int:
		PrintIntArrays(arrayToPrint,dataType,helperVar,columnSize,rowSize, devider);
		break;
	case Char:
		PrintCharArrays(arrayToPrint, dataType, helperVar, columnSize, rowSize, devider);
		break;
	}
}

void PrintIntArrays(int *arrayToPrint, StructDataType dataType,void* helper,int columnSize,int rowSize, char *devider) {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < columnSize; j++) {

			PrintNode(*(arrayToPrint+(i*columnSize)+j), dataType);
			if(j + 1 <columnSize)
				PrintDevider(devider);
		}
		printf("\n");
	}
}


void PrintCharArrays(char *arrayToPrint, StructDataType dataType, void* helper, int columnSize, int rowSize, char *devider) {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < columnSize; j++) {

			PrintNode(*(arrayToPrint + (i*columnSize) + j), dataType);
			if (j + 1 <columnSize)
				PrintDevider(devider);
		}
		printf("\n");
	}
}

void PrintNode(void *node, StructDataType dataType) {
	switch (dataType)
	{
	case Int: printf("%d", node);
		break;
	case Double: printf("%lf", node);
		break;
	case Char: printf("%c", node);
		break;
	}
}

void PrintDevider(char *devider) {
	printf("%s", devider);
}



