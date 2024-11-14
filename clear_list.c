#include "apc.h"

int clear_list(Dlist **head)
{
    
    if(*head==NULL)
    {
        return FAILURE;
    }
    
    Dlist *temp;
    
    while(*head!=NULL)
    {
        temp=*head;
        
        *head=(*head)->next;
        
        free(temp);
    }
    *head=NULL;
    return SUCCESS;

}
