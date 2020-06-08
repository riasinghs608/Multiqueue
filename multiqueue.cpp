#include<stdio.h>

static int b=0,q,queue[2][100];
int qu[100];

void enq();
void delq();
void display();
void chc();


void enq()
{
	int n,i,a;
	
	printf("\nEnter the queue no  : ");
	scanf("%d",&a);
	
	printf("\nEnter the element : ");
	scanf("%d",&n);
	qu[queue[1][a-1]]=n;
	
	queue[1][a-1]=queue[1][a-1]+1;
	
	chc();
}

void delq()
{
	int i,a;
	char c;
	
	printf("\nEnter the queue no  : ");
	scanf("%d",&a);
	
	if(queue[1][a-1]==queue[0][a-1])
	{
		printf("\nEmpty");
	}
	else
	{
		printf("\nELement removed is : %d",qu[queue[0][a-1]]);
		
		for(i=queue[0][a-1];i<(queue[1][a-1])-1;i++)
		{
			qu[i]=qu[i+1];
		}
		queue[1][a-1]=queue[1][a-1]-1;
		
		chc();
		
	}	
}


void display()
{
	int i=0;
	int a,j;
	
	printf("\nThe elements are : \n");
	for(j=0;j<q;j++)
	{
		for(i=queue[0][j];i<queue[1][j];i++)
		{
			printf("%d\n",qu[i]);
		}
		printf("\n\n");
	}
	
	chc();
}

void chc()
{
	int ch;
	printf("\n1.Insert \n2.Delete \n3.Display");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : enq();
		         break;
		         
		case 2 : delq();
		         break;
		         
		case 3 : display();
		         break;
	}

}

main()
{
	int k,i,l=0;
	
	
	queue[0][0]=0;
	printf("\nEnter the number of queues : ");
	scanf("%d",&q);
	
	printf("\nEnter the size of each queue : ");
	for(i=0;i<q;i++)
	{
		printf("\nSize of queue  %d \n",i+1);
		scanf("%d",&k);
		l=l+k;
		queue[0][i+1]=l;
		queue[1][i+1]=l;
	}
	chc();
}
