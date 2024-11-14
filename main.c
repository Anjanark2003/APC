/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
int main(int argc,char *argv[])
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL,*tailR=NULL;
	char option,operator;

	if(argc<3)
	{
		printf("Please provide <op1> <op2>");
		return FAILURE;
	}
        
	char *op1=argv[1];
    char *op2=argv[2];

	int num1=atoi(op1);
	int num2=atoi(op2);
	if(num1<0 || num2<0)
	{
		printf("Please provide 2 positive numbers\n");
		return FAILURE;
	}
	
	slice_into_list(op1,&head1,&tail1);
	slice_into_list(op2,&head2,&tail2);


    
	do
	{
		
		/* Code for reading the inputs */
		
		/* Function for extracting the operator */
		printf("Enter the operator : ");
		scanf(" %c",&operator);

		//int num1=atoi(op1);
		//int num2=atoi(op2);
		
		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
				
				if(num1==0 && num2==0)
				{
					printf("Result : 0\n");
				}
				else if(num1==0 && num2!=0)
				{
					printf("Result : %d\n",num2);
				}
				else if(num1!=0 && num2==0)
				{
					printf("Result : %d\n",num1);
				}
				else if(addition(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				{
					printf("Result : ");
					print_list(headR);
					printf("\n");
				}
				break;
				
			case '-':	
				/* call the function to perform the subtraction operation */

				if(num1==0 && num2==0)
				{
					printf("Result : 0\n");
				}
				else if(num1==0 && num2!=0)
				{
					printf("Result : %d\n",-(num2));
				}
				else if(num1!=0 && num2==0)
				{
					printf("Result : %d\n",num1);
				}
				else if(subtraction(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				{
					printf("Result : ");
				    print_list(headR);
				    printf("\n");
				}	

				break;
			case '*':	
				/* call the function to perform the multiplication operation */
				if(num1==0 || num2==0)
				{
					printf("Result : 0\n");
				}
				else if(multiplication(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				{
					printf("Result : ");
				    print_list(headR);
				    printf("\n");
				}	
				break;
			case '/':	
				/* call the function to perform the division operation */
				/*if(num1==0 && num2!=0)
				{
					printf("Result : 0\n");
				}
				else if(num1!=0 && num2==0 || num1==0 && num2==0)
				{
					printf("Invalid\n");
				}
				else if(division(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				{
					printf("Result : ");
				    print_list(headR);
				    printf("\n");
				}*/
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		printf("Want to continue? Press [yY | nN]: ");
		scanf(" %c", &option);
		clear_list(&headR);
	    headR=NULL;
	}while (option == 'y' || option == 'Y');
    
	return 0;
}
void slice_into_list(char *num,Dlist **head,Dlist **tail)
{
	int len=strlen(num);
	int padding=(4-(len%4))%4; //to find the number of zeroes to padd
	int new_len=padding+len;
	char padded_num[new_len+1];
	for(int i=0;i<padding;i++)
	{
		padded_num[i]='0';
	}
	strcpy(padded_num+padding,num);
	padded_num[new_len]='\0';
	int chunk_value;
	for(int i=new_len;i>0;i-=4)
	{
	   int start=(i-4)>0?i-4:0;
	   char temp[5]={0};  //+null character
	   strncpy(temp,padded_num+start,4);
	   temp[4]='\0';
	   chunk_value=atoi(temp);
	   dl_insert_last(head,tail,chunk_value);
	}
}


