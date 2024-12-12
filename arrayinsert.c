#include<stdio.h>
int main()
{
	int a[100],n,i,pos,val;
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
	printf("enter the position of the value to be inserted:\t");
	scanf("%d",&pos);
	printf("Enter your value:\t");
	scanf("%d",&val);
	for(i=n-1;i>=pos-1;i--)
	{
		a[i+1]=a[i];
	}
	a[pos-1]=val;
	printf("resultant array is:\n");
	for(i=0;i<=n;i++)
	{	
		printf("%d\n",a[i]);
	}
	return 0;
}
