#include<stdio.h>
int main()
{
	int a[100],n,i,pos;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("entered array:");
	for(i=0;i<n;i++)
	{
		printf(" %d\t",a[i]);
	}
	printf("Enter the position of the element to be deleted:");
	scanf("%d",&pos);
	if(pos>=n+1||pos<1)
	printf("deletion not possible.\n");
	else
	{
		for(i=pos-1;i<n-1;i++)
		{
			a[i]=a[i+1];
		}
		printf("resultant array is\n");
		for(i=0;i<n-1;i++)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
