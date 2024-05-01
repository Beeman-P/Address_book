#include<stdio.h>
#include<string.h>
#include "main.h"

Status add_contact(address *add)
{
	printf("0 Back\n1 Add name   : \n2 Add number : \n3 Add Email  : \n");
	printf("plese Select the option : ");
	int op;
	char na[20]=" ";
        char p[13]=" ";
        char e[50]=" ";
        scanf("%d",&op);
	while(op!=0)
	{
	    if(op<=3)
	    {
	     switch(op)
	     {
		     case 1:
				printf("Enter a name(less than 20 charater) : ");
				scanf(" %[^\n]",na);
				strcpy(add->name,na);
				strcat(add->name,",");
				fwrite(add->name,strlen(add->name),sizeof(char),add->file);
				break;
		
		     case 2:
				printf("Enter the phone number : ");
				scanf("%s",p);
				strcpy(add->ph,p);
				strcat(add->ph,",");
				fwrite(add->ph,strlen(add->ph),sizeof(char),add->file);
				break;
		     case 3:
				printf("Enter the emailid : ");
				scanf("%s",e);
				strcpy(add->email,e);
				strcat(add->email,",");
				fwrite(add->email,strlen(add->email),sizeof(char),add->file);
				break;
	     }
	    }
	    else
	    {
		    printf("Enter the Correct option \n");
		    printf("*************************\n");
	    }
	printf("0 Back\n1 Add name   : %s\n2 Add number : %s\n3 Add Email  : %s\n",na,p,e);
	printf("plese Select the option : ");
	scanf("%d",&op);
	}
      return a_sucess;     
}
