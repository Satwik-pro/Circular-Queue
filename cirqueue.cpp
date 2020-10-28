#include<stdio.h>
#define size 10
void insert(int);
void remove(void);
void display(void);
struct cir_queue
{
	int item[size];
	int front,rear;
}cq;
void insert(int val)
{
	if((cq.front==0 && cq.rear==size-1) || cq.front==cq.rear+1)
	{
		printf("\nElement can't be added because queue is full\n");
	}
	else if(cq.front==-1)
	{
		cq.front=0;
		cq.rear=0;
	}
	else if(cq.rear==size-1 && cq.front!=0)
	{
		cq.rear=0;
	}
	else
	{
		cq.rear=cq.rear+1;
	}
	cq.item[cq.rear]=val;
}
void remove()
{
	if(cq.front==-1)
	{
		printf("\nElement can't be removed because queue is empty\n");
	}
	else if(cq.front==cq.rear)
	{
		printf("\nDELETED ELEMENT : %d",cq.item[cq.front]);
		cq.front=-1;
		cq.rear=-1;
	}
	else if(cq.front==size-1)
	{
		printf("\nDELETED ELEMENT : %d",cq.item[cq.front]);
		cq.front=0;
	}
	else
	{
		printf("\nDELETED ELEMENT : %d",cq.item[cq.front]);
		cq.front=cq.front+1;
	}
}
void display()
{
	int iloop,temp_front,temp_rear;
	temp_front=cq.front;
	temp_rear=cq.rear;
	if(temp_front==-1)
	{
		printf("\nQueue is empty\n");
	}
	else if(temp_front<=temp_rear)
	{
		for(iloop=temp_front;iloop<=temp_rear;iloop++)
		{
			printf("\nQueue[%d]=%d",iloop,cq.item[iloop]);
		}
	}
	else
	{
		for(iloop=temp_front;iloop<=size-1;iloop++)
		{
			printf("\nQueue[%d]=%d",iloop,cq.item[iloop]);
		}
		temp_front=0;
		for(iloop=temp_front;iloop<=temp_rear;iloop++)
		{
			printf("\nQueue[%d]=%d",iloop,cq.item[iloop]);
		}
	}
}
int main()
{
	char c;
	int a[50],i,n,d,r;
	cq.front=-1;
	cq.rear=-1;
	do
	{
	printf("\n*********** CIRCULAR QUEUE ***********\n");
	printf("\n1.INSERT ELEMENTS IN QUEUE \n");
	printf("\n2.DELETE ELEMENTS FROM THE QUEUE \n");
	printf("\n3.DISPLAY ELEMENTS IN QUEUE \n");
	printf("\nSELECT AN OPTION (1-3)\n");
	fflush(stdin);
	scanf("%c",&c);
	switch(c)
	{
		case'1' :	printf("\nEnter number of elements to be added in the queue\n");
				scanf("%d",&n);
				printf("\nEnter %d elements one by one to be added in the queue\n",n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&a[i]);
					insert(a[i]);
				}
				break;
		case'2' :	printf("\nEnter number of elements you want to delete from the queue\n");
				scanf("%d",&d);
				for(i=0;i<d;i++)
				{
					remove();
				}
				break;
		case'3' :	display();
				break;
		default :	printf("\nYou have entered wrong option\n");
	}
	printf("\nDo you want to continue (10)->YES or (0)->NO \nENTER YOUR CHOICE\n");
	scanf("%d",&r);
	}while(r==10);
	return 0;
}
