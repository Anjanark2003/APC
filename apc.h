#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

int main(int argc,char *argv[]);
void slice_into_list(char *num,Dlist **head,Dlist **tail);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int dl_insert_last(Dlist **head, Dlist **tail, data_t data);
void print_list(Dlist *headR);
int clear_list(Dlist **head);
void reverse_list(Dlist **head);
#endif
