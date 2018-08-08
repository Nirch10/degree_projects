#include "Queue_point.h"
#include "Stack_point.h"
#include "Printer.h"


void PrintStack(STRUCT_TYPE *s, StructDataType dataType,void *helperVar, char *devider);
void PrintQueue(STRUCT_TYPE *q, StructDataType dataType, void *helperVar, char *devider);
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

void PrintArrayStruct(void* arrayToPrint, StructDataType arrayDataType, void * size,int dimension,char *devider) {
	switch (dimension)
	{
	case 1: PrintArray(arrayToPrint, arrayDataType, size,devider);
		break;
	case 2: print2DArray(arrayToPrint, arrayDataType, size);
		break;
	}
}

void PrintStack(STRUCT_TYPE *s, StructDataType dataType,void *helperVar, char *devider){
	//Not generic type
	while (!stack_is_empty(s) ){
		pop(s, &helperVar);
		PrintNode(helperVar, dataType);
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

void PrintArray(void* arrayToPrint, StructDataType dataType, void *helperVar, char *devider){
	for (int i = 0; i < helperVar; i++) {
		PrintNode(*(arrayToPrint + i), dataType);
	}
}

void print2DArray(){}

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



