#include "Queue_point.h"
#include "Stack_point.h"
#include "Printer.h"


void PrintStack(STRUCT_TYPE *s, StructDataType dataType);
void PrintQueue(STRUCT_TYPE *q, StructDataType dataType);
void PrintNode(stack_type node, StructDataType dataType);

void Print(STRUCT_TYPE *structToPrint, StructType typeOfStruct, StructDataType dataType) {
	switch (typeOfStruct)
	{
	case Stack:PrintStack(structToPrint,dataType);
		break;
	case Queue:PrintQueue(structToPrint,dataType);
		break;
	}
}

void PrintStack(STRUCT_TYPE *s, StructDataType dataType){
	//Not generic type
	stack_type currentNode;
	while (!stack_is_empty(s) ){
		pop(s, &currentNode);
		PrintNode(currentNode, dataType);
	}
}

void PrintQueue(STRUCT_TYPE *q, StructDataType dataType) {
	//Not generic type
	stack_type currentNode;
	while (!queue_is_empty(q)) {
		dequeue(q, &currentNode);
		PrintNode(currentNode, dataType);
	}
}

void PrintNode(stack_type node, StructDataType dataType) {
	switch (dataType)
	{
	case Int: printf("%d , ", node);
		break;
	case Double: printf("%lf , ", node);
		break;
	case Char: printf("%c , ", node);
		break;
	}
}


