#include <stdio.h>
#include <string.h>
#include "Queue_point.h"
#include "Stack_point.h"
#include "Printer.h"


int IsSimetricQueue(queue *q1, queue *q2);
void ConvertQueueToStack(queue *q, stack *s,int size);
void SortStack(stack *s);
queue_type GetMinVarInQueue(queue *q);

typedef stack struct_type;


void main() {
	queue queue1, queue2;
	char a = "";
	stack s1;
	int queueData = 0, stackQueue = 0;
	int arr[6] = { 1,2,2,4,5,6 };
	int arrc[3] = { 'a','1','123'};
	int arr2[5][4] = { {1,2,102,4},{1,2,12,7},{23,23,43,765},{43,78,9,2},{10,12,124,5} };
	int* parr = arr,parrc = arrc;
	int **parr2 = arr2;
	create_stack(&s1);
	create_queue(&queue1);
	create_queue(&queue2);
	push('a', &s1);
	push('k', &s1);
	push('d', &s1);
	push('f', &s1);
	push('b', &s1);
	enqueue('5', &queue1);
	enqueue('6', &queue1);
	enqueue('7', &queue1);
	enqueue('8', &queue1);
	enqueue('8', &queue2);
	enqueue('8', &queue2);
	enqueue('6', &queue2);
	enqueue('5', &queue2);
	printf("\n");
	PrintComplexStruct(&s1, Stack, Char, '0', "\n");
	printf("\n");
//	PrintArrayStruct(parrc, Char, 1, 3, 1, ' ^ ');
	PrintArrayStruct(parr, Int, 1, 6,1, "*");
	printf("\n");
	printf("\n");
	PrintArrayStruct(parr2, Int, 2, 4,5, "	-	");
	printf("\n");
	printf("\n");
	PrintComplexStruct(&queue1, Queue, Char, "f", "	");
	printf("\n");
	PrintComplexStruct(&queue2, Queue, Char,5,",");
	//printf("%d", IsSimetricQueue(&queue1, &queue2));
}


int IsSimetricQueue(queue *q1, queue *q2) {
	stack helpStack;
	int dataS = 0, dataQ = 0, flag = 1;
	create_stack(&helpStack);
	if (size_of_queue(q1) != size_of_queue(q2))return 0;
	ConvertQueueToStack(q2, &helpStack, size_of_queue(q2));
	while (!stack_is_empty(&helpStack)) {
		pop(&helpStack, &dataS);
		dequeue(q1, &dataQ);
		if (dataQ != dataS)return 0;
	}
	return 1;
}

void ConvertQueueToStack(queue *q, stack *s, int size) {
	int data = 0;
	for (int i = 0; i < size; i++) {
		dequeue(q, &data);
		push(data, s);
		enqueue(data, q);
	}
}

void SortStack(stack *s) {
	queue helperQue;
	stack_type helperVar;
	create_queue(&helperQue);
	while(!stack_is_empty(s)){
		pop(s, &helperVar);
		enqueue(helperVar, &helperQue);
	}
	while (!queue_is_empty(&helperQue)) {
		push(GetMinVarInQueue(&helperQue), s);
	}
}

queue_type GetMinVarInQueue(queue *q) {
	queue_type sTypeMin;
	queue_type helperVar;
	dequeue(q, &sTypeMin);
	for (int i = 0; i< size_of_queue(q); i++) {
		if (queue_front(q, &helperVar) < sTypeMin)
		{
			enqueue(sTypeMin, q);
			dequeue(q, &sTypeMin);
		}
		else {
			dequeue(q, &helperVar);
			enqueue(helperVar, q);
		}
	}
	return sTypeMin;
}




//queue qPointer;
///*qPointer->items_num = 0;
//qPointer->front = null;
//qPointer->end = null;*/
//int data = 0;
//create_queue(&qPointer);
//enqueue(5, &qPointer);
//enqueue(6, &qPointer);
//enqueue(7, &qPointer);
//enqueue(8, &qPointer);
//while (!queue_is_empty(&qPointer)){
//	printf("%d", qPointer.rear->data);
//	dequeue(&qPointer, &data);
//}