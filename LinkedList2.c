#include<stdlib.h>
#include<stdio.h>
int i;
typedef struct node{
 	int x;
	struct node *next;	
}n;

void write(n*r)
{
	while(r)
	{
		printf("%d---",r->x);
		r=r->next;
	}	
}
n* add(n* r,int i)
{
	if(r == NULL)									
	{
		r=(n*)malloc(sizeof(n));
		r->x=i;
		r->next=NULL;
		return r;
	}
	if(r->x >= i)
	{
		n* temp=(n*)malloc(sizeof(n));
		temp->x=i;
		temp->next=r;
		return temp;
	}	
	else
	{
		n * iter=r;
		n* temp =(n*)malloc(sizeof(n));
		temp->x=i;
		while(iter->x < i && iter->next != NULL)
		{
			iter=iter->next;
		}
		if(iter->next == NULL)
		{
			iter->next=temp;
			temp->next=NULL;
			return iter;
		}
		else
		{
			temp->next=iter->next;
			iter->next=temp;
			return iter;
		}

	}
}
int main(){
	n * root=NULL;
	root=add(root,250);
	root=add(root,300);
	root=add(root,275);
	root=add(root,285);
	write(root);
	
}
