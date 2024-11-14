/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	Dlist *temp1=*head1;
	Dlist *temp2=*head2;
	int count1=0;
	int count2=0;
	//int carry=0;

	while(temp1!=NULL)
	{
		count1++;
		temp1=temp1->next;
	}

	while(temp2!=NULL)
	{
		count2++;
		temp2=temp2->next;
	}

	for(int i=0;i<count1+count2;i++)
	{
		Dlist *new=malloc(sizeof(Dlist));
		new->data=0;
		new->prev=NULL;
		new->next=*headR;
		if(*headR!=NULL)
		{
			(*headR)->prev=new;
		}
		*headR=new;
	}

	temp1=*head1;
    Dlist *shift;
	for(int i=0;i<count1;i++)
	{
		int carry=0;
		temp2=*head2;
	    shift=*headR;

		for(int k=0;k<i;k++)
		{
			shift=shift->next;
		}
		for(int j=0;j<count2;j++)
		{
			int data1=temp1->data;
			int data2=temp2->data;
			int mul=data1*data2+shift->data+carry;
			shift->data=mul%10000;
			carry=mul/10000;
			shift=shift->next;
			temp2=temp2->next;
		}
       
		while(carry>0 && shift!=NULL)
		{
			int sum=shift->data+carry;
			carry=sum/10000;
			shift->data=sum%10000;
			shift=shift->next;
		}
		temp1=temp1->next;

	}
    reverse_list(headR);
	return SUCCESS;
}

