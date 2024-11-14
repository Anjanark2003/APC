#include "apc.h"

void print_list(Dlist *headR)
{
	/* Cheking the list is empty or not */
	if (headR == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (headR)		
	    {
		    /* Printing the list */
		   printf("%04d", headR -> data);

		    /* Travering in forward direction */
		   headR = headR -> next;
	    }
    }

	
}
