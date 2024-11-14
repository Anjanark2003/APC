/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	/* Definition goes here */
	Dlist *temp1=*head1;
	Dlist *temp2=*head2;
	int count1=0;
	int count2=0;
	int carry=0;

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
	//reinitialize the value of temp1 and temp2 as head1 and head2
	
	temp1=*head1;
	temp2=*head2;

	while(temp1!=NULL || temp2!=NULL || carry>0)
	{
	    int data1=temp1!=NULL?temp1->data:0;
	    int data2=temp2!=NULL?temp2->data:0;

	    int sum=data1+data2+carry;

	    carry=sum/10000;
	                
	    Dlist *new=malloc(sizeof(Dlist));

		if(new==NULL)
		{
			return FAILURE;
		}

			new->data=sum%10000; //to get the 4 bits 
			new->prev=NULL;
			new->next=NULL;
                        
			//perform insert_at_first operation

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
		return SUCCESS;
	

	

}
