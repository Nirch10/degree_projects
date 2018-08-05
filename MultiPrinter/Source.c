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

	int queueData = 0, stackQueue = 0;
	create_queue(&queue1);
	create_queue(&queue2);
	enqueue('5', &queue1);
	enqueue('6', &queue1);
	enqueue('7', &queue1);
	enqueue('8', &queue1);
	enqueue('8', &queue2);
	enqueue('8', &queue2);
	enqueue('6', &queue2);
	enqueue('5', &queue2);
	Print(&queue1, Queue, Char);
	printf("\n");
	Print(&queue2, Queue, Char);
	printf("%d", IsSimetricQueue(&queue1, &queue2));
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