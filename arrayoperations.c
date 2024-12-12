#include<stdio.h>
#include<stdlib.h>
int a[100],i;
int a_count=0;
void create()
{
	int i;
	printf("\n\n.....................................\n");
	printf("\n Total number of elements in the array :");
	scanf("%d",&a_count);
	printf("\nEnter %d Elements \n\n",a_count);
	for(i=0;i<a_count;i++)
	{
		printf("a[%d] :",i+1);
		scanf("%d",&a[i]);
		printf("\n");
	}
	printf("\n\n.....................................\n");
}
void insert()
{
	int ins_pos,i,new_val;
	printf("\n\n.....................................\n");
	printf("\nPosition of insertion :");
	scanf("%d",&ins_pos);
	for(i=a_count-1;i>=ins_pos-1;i--)
	{
		a[i+1]=a[i];
	}
	printf("which value you want to add :");
	scanf("%d",&new_val);
	a[ins_pos-1]=new_val;
	printf("\n\nNew array is : \n\n");
	a_count=a_count+1;
	for(i=0;i<a_count;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n\n.....................................\n");
}
void delete()
{
	int del_pos,i;
	printf("\n\n.....................................\n");
	printf("\nPosition of array to delete an element :");
	scanf("%d",&del_pos);
	for(i=del_pos-1;i<a_count-1;i++)
	{
		a[i]=a[i+1];
	}
	printf("\n\nNew array is : \n\n");
	a_count=a_count-1;
	for(i=0;i<a_count;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n\n.....................................\n");
}
void view()
{
	int i;
	printf("\n\n.....................................\n");
	printf("elements are:\n");
	for(i=0;i<a_count;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n\n.....................................\n");
}
int main()
{
	int opt=0;
	while(1)
	{
		printf("\n\n..............................\n");
		printf("1) CREATE\n");
		printf("2) INSERT\n");
		printf("3) DELETE\n");
		printf("4) VIEW\n");
		printf("0) QUIET\n\n");
		printf("choose your option :");
		scanf("%d",&opt);
		printf("\n\n..............................\n");
		if(opt==0)
			exit(0);
		switch(opt)
		{
			case 1:
				create();
				break;
			case 2:
				insert();
				break;	
			case 3:
				delete();
				break;
			case 4:
				view();
				break;
			default:
				printf("Invalid option! Try Again.");
		}
	}
	
	printf("ok");
	return 0;
}

		
		
