/*Design, Develop and Implement a menu driven Program for the following 
operations on Circular QUEUE of Characters (Array Implementation of 
Queue with maximum size MAX) .
a. Insert an Element onto Circular QUEUE.
b. Delete an Element from Circular QUEUE.
c. Demonstrate Overflow and Underflow situations on Circular QUEUE.
d. Display the status of Circular QUEUE. 
e. Exit Support the program with appropriate functions for each of the 
above operations.*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

char cq[MAX];
int front=-1,rear=-1;

void enqueue()
{
    if(front==-1&&rear==-1){
         front=rear=0;
         printf("Enter the Character to insert in queue :");
         scanf(" %c",&cq[rear]);
    }
    else if((rear+1)%MAX==front){
     printf("Queue Overflow!");
    }
    else{
        rear=(rear+1)%MAX;
        printf("Enter the Character to insert in queue :");
         scanf(" %c",&cq[rear]);
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue Underflow!");
    }
    else if(front==rear){
        printf("Deleted Character is %c",cq[front]);
        front=rear=-1;
        }
    else{
         printf("Deleted Character is %c",cq[front]);
         front=(front+1)%MAX;
    }
}
void display(){
    int i;
    if(front==-1&&rear==-1){
        printf("Queue Underflow!");
    }
    else{
        for(i=front;i!=rear;i=(i+1)%MAX){
            printf("%c\t",cq[i]);
        }
        printf("%c\n",cq[rear]);
    }
}
void main()
{
    int ch;
    while (1)
    {   printf("\nCircular Queue Operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:enqueue();break;
        case 2:dequeue();break;
        case 3:display();break;
        case 4:exit(0);
        default :printf("\nINVALID CHOICE !!\n");
        }
    }
}
/*OUTPUT:-
Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 1
Enter the Character to insert in queue :a

Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 1
Enter the Character to insert in queue :b

Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 1
Enter the Character to insert in queue :c

Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 3
a       b       c

Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 2
Deleted Character is a

Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 3
b       c

Circular Queue Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your Choice: 4
*/