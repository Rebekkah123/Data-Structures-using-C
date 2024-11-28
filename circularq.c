#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cqueue[MAX];
int front=-1,rear=-1;
void enqueue(){
	int el;
	printf("\nEnter the element to be added:");
	scanf("%d",&el);
	if ((rear+1)%MAX==front)
		printf("Overflow!");
	else{
		if (front==-1)
			front=0;
		rear=(rear+1)%MAX;
		cqueue[rear]=el;
	}
}
void dequeue(){
	if (front==-1){
		printf("Underflow!");
	}
	else{
		printf("%d dequeued from queue",cqueue[front]);
		if (front==rear)
			front=rear=-1;
		else
			front=(front+1)%MAX;
	}
}
void display(){
	int i;
	if (front==-1){
		printf("Empty Queue!");
	}
	else{
		for (i=front;i<=rear;i=(i+1)%MAX){
			printf("%d\t",cqueue[i]);
			if (i==rear){
				break;
			}
		}
	}
}
void main(){
	int choice;
	while (1){
		printf("\n1.enqueue into queue");
		printf("\n2.dequeue from queue");
		printf(" \n3.Display the elements\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default: 
				printf("\nInvalid option!!");
				break;
		}
	}
}

