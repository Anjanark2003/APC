/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	/* Definition goes here */

	Dlist *temp1=*head1;
	Dlist *temp2=*head2;
    int count1=0;
	int count2=0;
	int borrow=0;
    int is_op1_greater=1;
	

	temp1=*tail1;
	temp2=*tail2;
	
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data > temp2->data)
		{
			is_op1_greater=1;
			break;
		}
		else
		{
			is_op1_greater=0;
			break;
		}

		temp1=temp1->prev;
		temp2=temp2->prev;
	
	}
	
	
	
    if(is_op1_greater)
	{
		temp1=*head1;
		temp2=*head2;
	}
	else{
		temp1=*head2;
        temp2=*head1;
	}

	while(temp1!=NULL || temp2!=NULL)
	{
		
		int data1=temp1!=NULL?temp1->data:0;
		int data2=temp2!=NULL?temp2->data:0;
        data1-=borrow;
		if(data1<data2)
		{
			data1+=10000;
			borrow=1;
		}
        else
		{
			borrow=0;
		}

		int difference=data1-data2;
        
		Dlist *new=malloc(sizeof(Dlist));

		if(new==NULL)
		{
			return FAILURE;
		}
        new->data=difference%10000;
		new->prev=NULL;

		new->next=NULL;

		if(*headR==NULL)
		{
			*headR=new;
		}
		else
		{
			new->next=*headR;
			(*headR)->prev=new;
			*headR=new;
		}

		if(temp1!=NULL)
			temp1=temp1->next;
		if(temp2!=NULL) 
			temp2=temp2->next;
	}

	
	if(*headR!=NULL && !is_op1_greater)
	{
		(*headR)->data=-(*headR)->data;
	}
	else
	{
        (*headR)->data=(*headR)->data;
	}
	return SUCCESS;
}
