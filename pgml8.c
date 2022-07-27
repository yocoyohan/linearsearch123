#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
int x;
void linear(int a[],int x);
int n;
int i;

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	
	srand( (unsigned) time(NULL) * getpid()); 
	
	int a[100];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}
	printf("The array elements are :\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	printf("Enter the number you have to search :");
	scanf("%d",&x);
	gettimeofday(&t0, NULL);
	linear(a,x);
	gettimeofday(&t1, NULL);
	
	elapsed = timedifference_msec(t0, t1);

   	printf("Code executed in %f milliseconds.\n", elapsed);
	printf("\n");
}
void linear (int a[], int  x)
{
	int flag=0;
	for (i=0;i<n;i++)
	{
		if (a[i]==x)
		{
			flag =1;
			break;
		}
	}
	if (flag ==1)
	{
		printf("%d found at position %d\n",x,i+1);
	}
	else
	{
		printf("Element not found!\n");
	}
}
