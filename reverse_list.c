#include "apc.h"
void reverse_list(Dlist **head)
{
   Dlist *current=*head;
   Dlist *temp=NULL;
   while(current!=NULL)
   {
	temp=current->prev;
	current->prev=current->next;
	current->next=temp;
	current=current->prev;
   }
   if(temp!=NULL)
   {
	*head=temp->prev;
   }

   while(*head && (*head)->data==0)
   {
	  Dlist *temp=*head;
	  *head=(*head)->next;
	  if(*head!=NULL)
	  {
		(*head)->prev=NULL;
	  }
	  free(temp);
	  
	}
}